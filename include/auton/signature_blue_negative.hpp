#pragma once
#include "components.hpp"

void signature_blue_negtive(){
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(50.75, 11, 122);
    //normal arm code

    //back up arm code
    // arm.moveToState(ArmNamespace::State::WAIT);
    // pros::delay(300);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
    chassis.moveDistance(5, 500, {.maxSpeed = 127}, false);
    arm.moveToState(ArmNamespace::State::UP);
    pros::delay(500);
    chassis.moveToPoint(37.5, 17.5, 1000, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(24, 24, 1300, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToHeading(330, 800, {.maxSpeed = 127}, false); 
    chassis.waitUntilDone();
 
    chassis.moveDistance(20, 1000, {.maxSpeed = 127}, false);
    chassis.moveToPoint(24, 24, 900, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToPoint(19, 48, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(22, 900, {.maxSpeed = 127}, false);
    chassis.correctAt0({"front"});
    chassis.turnToPoint(5, 54, 700, {.maxSpeed = 127}, false);
    chassis.moveDistance(18, 1000, {.maxSpeed = 127}, false);
    chassis.moveToPoint(40, 45, 1100, {.forwards = false,  .maxSpeed = 127}, false);
    chassis.turnToHeading(30, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(20, 1100, {.maxSpeed = 127}, false);
    chassis.moveDistance(15, 900, {.maxSpeed = 90}, false);
    chassis.moveToPoint(24, 24, 1100, {.forwards = false,  .maxSpeed = 127}, false);
    chassis.turnToPoint(28, 0, 700, {.maxSpeed = 127}, false);
    chassis.moveToPoint(24, 0, 1800, { .maxSpeed = 37}, false);
}
