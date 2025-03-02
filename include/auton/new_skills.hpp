#pragma once
#include "components.hpp"

void skills() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);

    chassis.setPose(-61.5, 0, 90);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);

    pros::delay(300);

    chassis.moveToPoint(-48, 0, 1000, {}, false);

    chassis.turnToHeading(0, 1000, {}, false);

    chassis.moveToPoint(-48, -24, 1000, {}, false);

    // grab the first mobile goal
    holder.moveToState(HolderNamespace::State::HOLD);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveToPoint(-24, -24, 1000, {}, false);

    chassis.moveToPoint(0, -36, 1000, {}, false);

    // Raise the arm
    arm.moveToState(ArmNamespace::State::STOP);

    chassis.moveToPoint(24, -48, 1000, {}, false);

    chassis.moveToPoint(0, -48, 1000, {}, false);

    chassis.turnToHeading(180, 1000, {}, false);

    // Attempt for the first high wall stake
    arm.moveToState(ArmNamespace::State::UP);

    chassis.moveToPoint(0, -53, 1000, {}, false);

    chassis.moveToPoint(-24, -48, 1000, {}, false);

    arm.moveToState(ArmNamespace::State::DOWN);

    chassis.moveToPoint(-48, -48, 1000, {}, false);

    chassis.moveToPoint(-53, -48, 1000, {}, false);

    chassis.turnToHeading(150, 1000, {}, false);

    chassis.moveDistance(10, 1000, {}, false);

    chassis.turnToHeading(45, 1000, {}, false);

    chassis.moveToPoint(-53, -53, 1000, {.forwards = false}, false);

    conveyor.moveToState(ConveyorNamespace::State::REVERSE, 500);

    // Drop the first mobile goal
    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveDistance(20, 1000, {}, false);

    chassis.turnToHeading(90, 1000, {}, false);

    chassis.correctAt90({"back", "right"});

    chassis.moveToPoint(48, -48, 2000, {}, false);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 400);

    chassis.turnToHeading(45, 1000, {}, false);

    chassis.moveDistance(-24, 1000, {}, false);

    holder.moveToState(HolderNamespace::State::HOLD);

    chassis.moveToPoint(53, -53, 2000, {}, false);

}