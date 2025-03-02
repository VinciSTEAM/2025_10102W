#pragma once
#include "components.hpp"

void red_left_solo() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);

    chassis.setPose(-61, 13.5, 180);

    chassis.turnToHeading(209.3, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    arm.moveToState(ArmNamespace::State::UP, 1000);

    pros::delay(800);

    arm.moveToState(ArmNamespace::State::DOWN, 1000);

    chassis.moveToPoint(-24, 26, 1500, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(25, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(12, 1000);
    chassis.waitUntilDone();

    chassis.turnToHeading(5, 1000);

    chassis.moveDistance(9, 1000);

    chassis.moveDistance(-10, 1000, {.forwards = false, .maxSpeed = 70}, false);

    chassis.turnToHeading(-45, 1000, {}, false);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(10, 1000, {}, false);
    chassis.waitUntilDone();

    pros::delay(300);

    // doinker.moveToState(HolderNamespace::State::HOLD);

    // chassis.moveToPoint(-58, 58, 1500, {}, false);
    // chassis.waitUntilDone();

    // chassis.turnToHeading(140, 1000);

    // chassis.waitUntilDone();

    // doinker.moveToState(HolderNamespace::State::RELEASE);

    arm.moveToState(ArmNamespace::State::UP);

    chassis.moveToPoint(-28, 14, 2000, {.maxSpeed = 60}, false);

    chassis.waitUntil(30);
    doinker.moveToState(HolderNamespace::State::HOLD);
    chassis.turnToHeading(90, 2000, {.maxSpeed = 30}, false);

    conveyor.moveToState(ConveyorNamespace::State::STOP);
}