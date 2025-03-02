#pragma once
#include "components.hpp"

void blue_rush_sweep() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(56.5, -31, -90);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 1200);

    chassis.moveToPoint(24, -48, 900, {.maxSpeed = 100}, false);

    chassis.turnToHeading(-270, 900, {.maxSpeed = 90}, false);

    chassis.moveDistance(-12, 900, {.forwards = false, .maxSpeed = 60}, false);
    pros::delay(500);

    holder.moveToState(HolderNamespace::State::HOLD);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveToPoint(36, -48, 900, {.maxSpeed = 70}, false);

    chassis.turnToHeading(-90, 900, {.maxSpeed = 70}, false);

    holder.moveToState(HolderNamespace::State::RELEASE);
    // chassis.moveDistance(-10, 900, {.forwards = false, .maxSpeed = 70}, false);

    // chassis.moveDistance(5, 800, {.maxSpeed = 80}, false);

    chassis.turnToPoint(24, -24, 800, {.forwards = false, .maxSpeed = 80}, false);

    chassis.moveToPoint(24, -24, 800, {.forwards = false, .maxSpeed = 80}, false);
    holder.moveToState(HolderNamespace::State::HOLD);

    chassis.turnToPoint(48, -20, 900, {.maxSpeed = 70}, false);

    chassis.moveToPoint(52, -20, 900, {.maxSpeed = 70}, false);
    
    // corner sweep code below

    chassis.moveToPoint(58, -61, 2000, {.maxSpeed = 80}, false);
    pros::delay(500);

    doinker.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();
    
    chassis.turnToHeading(0, 900);
    pros::delay(600);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPoint(30, -48, 900, {}, false);

    chassis.turnToHeading(90, 900, {}, false);

    chassis.moveToPose(13, -17.5, 0, 2000, {.maxSpeed = 70}, false);
    
}