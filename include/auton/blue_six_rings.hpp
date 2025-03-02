#pragma once
#include "components.hpp"

void blue_six_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(52.25, 24, 90);

    chassis.moveToPoint(28, 24, 2000, {.forwards = false, .maxSpeed = 50}, false);

    chassis.waitUntil(21);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.moveToPose(9, 48, 0, 3000, {.lead = 0.3, .maxSpeed = 127}, false);

    chassis.moveToPoint(24, 24, 1200, {.forwards = false, .maxSpeed = 100}, false);

    chassis.moveToPoint(24, 39, 1000, {.maxSpeed = 127}, false);

    chassis.turnToHeading(85, 1000, {.maxSpeed = 127}, false);

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveToPoint(54, 59, 1520, {.maxSpeed = 127}, false);

    chassis.moveDistance(4, 1000, {.maxSpeed = 127}, false);

    pros::delay(200);

    chassis.moveDistance(10, 1000, {.forwards = false, .maxSpeed = 70}, false);

    chassis.turnToHeading(-180, 1000, {.maxSpeed = 100}, false);

    //intake_raiser.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPoint(35, 0, 2000, {}, false);
    //intake_raiser.moveToState(HolderNamespace::State::HOLD);
}
