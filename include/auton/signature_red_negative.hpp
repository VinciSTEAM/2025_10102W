#pragma once
#include "components.hpp"

void signature_red_negtive(){
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-51.25, 11, 238);
    //normal arm code

    //back up arm code
    // arm.moveToState(ArmNamespace::State::WAIT);
    // pros::delay(300);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
    chassis.moveDistance(5, 500, {.maxSpeed = 127}, false);
    arm.moveToState(ArmNamespace::State::UP);
    pros::delay(500);
    chassis.moveToPoint(-37.5, 17.5, 1000, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 24, 1300, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToHeading(38, 800, {.maxSpeed = 127}, false); 
    chassis.waitUntilDone();
 
    chassis.moveDistance(18, 1000, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 24, 900, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(0, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(20, 500, {.maxSpeed = 127}, false);
    chassis.correctAt0({"front"});
    chassis.turnToHeading(90, 500, {.maxSpeed = 127}, false);
    chassis.correctAt90({"left"});
    chassis.moveDistance(16, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-48, 48, 1300, {.forwards = false,  .maxSpeed = 127}, false);
    chassis.turnToHeading(330, 800, {.maxSpeed = 127}, false);

    chassis.moveDistance(15, 1100, {.maxSpeed = 127}, false);
    chassis.moveDistance(15, 1100, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-24, 24, 1100, {.forwards = false,  .maxSpeed = 127}, false);
    chassis.turnToPoint(-28, 0, 700, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 0, 1800, { .maxSpeed = 37}, false);
    
    // chassis.turnToPoint(-15, 36.5, 800, {.maxSpeed = 100}, false);
    // chassis.moveDistance(15, 1000, {.maxSpeed = 127}, false);
    // chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {}, false);
    // chassis.moveDistance(7, 600, {.maxSpeed = 127}, false);
    
    // chassis.moveToPoint(-24, 24, 1300, {.forwards = false, .maxSpeed = 100}, false);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    // chassis.turnToHeading(0, 600, {.maxSpeed = 127}, false);
    // chassis.correctAt0({"left"});

    // chassis.moveDistance(20, 600, {.maxSpeed = 127}, false);
    // chassis.correctAt0({"front"});
    // chassis.turnToPoint(-46, 9, 800, {.maxSpeed = 127}, false);
    // intake_raiser.moveToState(HolderNamespace::State::HOLD);

    // chassis.moveToPoint(-42, 9, 1500, {.maxSpeed = 127}, false);

    // intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    // chassis.moveDistance(-5, 500, {.forwards = false, .maxSpeed = 127}, false);
    // chassis.turnToPoint(-24, 0, 800, {.maxSpeed = 127}, false);
    // chassis.moveDistance(25, 3000, {.maxSpeed = 37}, false);


}
