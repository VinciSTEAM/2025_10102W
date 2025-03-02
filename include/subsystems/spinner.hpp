#pragma once

#include "pros/motors.hpp"

namespace SpinnerNamespace {

enum class State {  IDLE, FORWARD, BACKWARD };

class Spinner : public subsystem<State> {
    public:
        explicit Spinner(std::shared_ptr<pros::Motor> motor)
            : motor_(std::move(motor)) {
            motor_->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
            motor_->tare_position();
        }

        virtual ~Spinner() override = default; // Virtual destructor for safe inheritance

        bool stuckDetected() const {
            return motor_->get_actual_velocity() < STUCK_RPM and motor_->get_current_draw() > STUCK_CURRENT;
        }

        // Get motor object
        std::shared_ptr<pros::Motor> getMotor() { return motor_; }
    protected:
        std::shared_ptr<pros::Motor> motor_; // Encapsulate member variable

        // Task to control the arm's movement
        void runTask() override final {
            switch (currState) {
                case State::FORWARD: motor_->move(127); break;
                case State::BACKWARD: motor_->move(-127); break;
                case State::IDLE: motor_->move(0); break;
            }
        }
};

} // namespace SpinnerNamespace
