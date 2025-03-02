#pragma once
#include "components.hpp"

void blue_positive(){
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(50.75, -11, 58);
    //normal arm code

    //back up arm code
    // arm.moveToState(ArmNamespace::State::WAIT);
    // pros::delay(300);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
    chassis.moveDistance(5, 500, {.maxSpeed = 127}, false);
    arm.moveToState(ArmNamespace::State::UP);
    pros::delay(500);
    chassis.moveToPoint(37.5, -17.5, 1000, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(24, -24, 1300, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(170, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(20, 1000, {.maxSpeed = 127}, false);
    //add intake at the coner if possible
    

    chassis.moveToPoint(18, -21, 3000, {.maxSpeed = 60}, false);

}