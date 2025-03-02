#pragma once
#include "components.hpp"

void right_alliance_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    arm.resetRotation(3500.0f);

    chassis.setPose(59.5, 13, 180);

    arm.changeVelocity(0.7);

    chassis.turnToHeading(-222, 1000, {.maxSpeed = 70}, false);

    arm.moveToState(ArmNamespace::State::UP, 1000);

    pros::delay(1000);

    arm.changeVelocity(1);

    chassis.moveToPoint(28, 24, 2000, {.forwards = false, .maxSpeed = 50}, false);

    arm.moveToState(ArmNamespace::State::DOWN);

    chassis.waitUntil(21);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(24, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();

    pros::delay(300);
    chassis.turnToHeading(-120, 1000);
    chassis.moveDistance(-30, 1000, {.forwards = false, .maxSpeed = 100}, false);
    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPoint(18, 18, 2000, {.maxSpeed = 80});
}

void red_alliance_right_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    right_two_rings();
}

void blue_alliance_right_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    right_two_rings();
}

void no_alliance_color_right_two_rings() {
    conveyor.disable_color_sensor();
    right_two_rings();
}
