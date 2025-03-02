#pragma once

#include "pros/motor_group.hpp"
#include "lemlib/api.hpp"
#include "subsystem.hpp"

namespace ArmNamespace {

enum class State { DOWN, WAIT, UP, MANUAL_UP, IDLE };

class Arm : public subsystem<State> {
    public:
        Arm(std::shared_ptr<pros::Motor> motor, std::shared_ptr<pros::Rotation> rotation,
            lemlib::ControllerSettings armAngularController)
            : motor_(std::move(motor)),
              rotation_(std::move(rotation)),
              armAngularPID(armAngularController.kP, armAngularController.kI, armAngularController.kD,
                            armAngularController.windupRange, true) {
            motor_->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
            motor_->tare_position();
            motor_->set_brake_mode(pros::MotorBrake::hold);
            rotation_->set_position(0);
            rotation_->reset();
        }

        ~Arm() override = default;

        // Controls the arm based on button inputs
        void control(bool button_1, bool button_2, bool button_3) {
            if (button_1 or button_2) manual_ = false;
            if (button_3) manual_ = true;

            if (manual_) {
                // Manual mode handling
                if (button_3) {
                    moveToState(State::MANUAL_UP);
                } else {
                    moveToState(State::IDLE);
                }
            } else {
                // Auto mode handling
                if (button_1) {
                    moveToState(State::UP);
                } else if (button_2) {
                    // For button_2, check current state and decide:
                    // If the current state is DOWN, go to WAIT; otherwise, go to DOWN.
                    if (currState == State::DOWN) {
                        moveToState(State::WAIT);
                    } else {
                        moveToState(State::DOWN);
                    }
                }
                // Optionally, if no button is pressed and we're not in WAIT, ensure we go to DOWN.
                else if (currState != State::WAIT) {
                    moveToState(State::DOWN);
                }
            }
        }

        void changeVelocity(float ratio) { ratio_ = ratio; }

        bool getManual() { return manual_; }

        // Getter for rotation sensor
        std::shared_ptr<pros::Rotation> getRotation() const { return rotation_; }

        // Getter for the arm's state as a string
        std::string getState() const {
            switch (currState) {
                case State::UP: return "UP";
                case State::WAIT: return "WAIT";
                case State::DOWN: return "DOWN";
                case State::MANUAL_UP: return "MANUAL_UP";
                default: return "UNKNOWN";
            }
        }

        void moveToState(State newState) {
            armAngularPID.reset();
            currState = newState;
        }

        void moveToState(State newState, int time) {
            timer.set(time);
            moveToState(newState);
        }

        void resetRotation(float rotation) { rotation_->set_position(rotation); }
    private:
        std::shared_ptr<pros::Motor> motor_;
        std::shared_ptr<pros::Rotation> rotation_;
        float ratio_ = 1;
        bool manual_;

        // angular motion controller
        lemlib::PID armAngularPID;

        // Task to control the arm's movement
        void runTask() override final {
            if (currState == State::DOWN) motor_->set_brake_mode(pros::MotorBrake::coast);
            else motor_->set_brake_mode(pros::MotorBrake::hold);

            switch (currState) {
                case State::UP:
                    if (rotation_->get_position() <= MAX_DEGREES) {
                        motor_->move(127 * ratio_);
                    } else {
                        motor_->move(0);
                    }
                    break;
                case State::WAIT:
                    if (float angularError = (WAIT_DEGREES - rotation_->get_position()) / 100.0;
                        abs(angularError) > 2) {
                        motor_->move(armAngularPID.update(angularError));
                    } else {
                        motor_->move(0);
                    }
                    break;
                case State::DOWN:
                    if (rotation_->get_position() > DOWN_DEGREES) {
                        motor_->move(-127 * ratio_);
                    } else {
                        motor_->move(0);
                    }
                    break;
                case State::MANUAL_UP:
                    if (float angularError = (DISCORE_DEGRESS - rotation_->get_position()) / 100.0;
                        abs(angularError) > 2) {
                        motor_->move(armAngularPID.update(angularError));
                    } else {
                        motor_->move(0);
                    }
                    break;
                case State::IDLE: motor_->move(0); break;
            }
        }
};
} // namespace ArmNamespace