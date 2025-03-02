#pragma once
#include "components.hpp"

void skills_states() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-62.25, 0, 90);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    pros::delay(300);
    chassis.moveToPoint(-50, 0, 700, {}, false);
    chassis.turnToHeading(0, 800, {}, false);
    chassis.moveDistance(-24, 1000, {.forwards = false, .maxSpeed = 80}, true);
    chassis.waitUntil(20);
    holder.moveToState(HolderNamespace::State::HOLD);
    pros::delay(80);
    chassis.turnToPoint(-24, -24, 700, {.maxSpeed = 80}, false);
    chassis.moveToPoint(-27, -24, 800, {}, false);
    
   
    chassis.moveToPoint(25, -48.5, 1800, {.maxSpeed = 100}, true);
    chassis.waitUntil(20);
    arm.moveToState(ArmNamespace::State::WAIT);
    chassis.waitUntilDone();
    
    chassis.moveToPoint(4, -40, 1000, {.forwards = false, .maxSpeed = 90}, false);
    
    chassis.turnToHeading(180, 800, {}, false);
    
    
    chassis.moveDistance(25, 1000, {.maxSpeed = 80}, false);
    
    conveyor.moveToState(ConveyorNamespace::State::STOP);

    arm.moveToState(ArmNamespace::State::UP, 300);
    pros::delay(300);
   

    chassis.moveDistance(-10, 600, {.forwards = false}, false);
    chassis.waitUntilDone();
    arm.moveToState(ArmNamespace::State::DOWN, 500);
    chassis.turnToHeading(270, 800, {}, false);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    
    chassis.moveToPoint(-57,- 48, 1500, {.maxSpeed = 85}, false);
    chassis.correctAt270({"forward"});
    chassis.turnToHeading(150, 700, {}, false);
    chassis.moveDistance(15,700, {}, false);
    chassis.turnToHeading(90, 800, {}, false);
    chassis.correctAt90({"right"});
    chassis.moveDistance(-13, 800, {.forwards = false, .maxSpeed = 80}, false);

    holder.moveToState(HolderNamespace::State::RELEASE);

    conveyor.moveToState(ConveyorNamespace::State::INTAKE_FORWARD);
    
    //first half

    chassis.moveToPoint(39.5,-48, 2000, {}, false);
    chassis.turnToHeading(90, 600, {}, false);
    chassis.correctAt90({"front", "right"});
    chassis.turnToPoint(60, -24, 700, {.forwards = false}, false);
    chassis.moveToPoint(60, -24, 1200, {.forwards = false, .maxSpeed = 60}, true);
    chassis.waitUntil(27);
    holder.moveToState(HolderNamespace::State::HOLD);
    pros::delay(150);
    chassis.turnToPoint(66,-58, 1000, {.forwards = false}, false);
    holder.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-33, 1000, {.forwards = false}, false);
    chassis.moveToPoint(48, -48, 1000, {}, false);
    arm.moveToState(ArmNamespace::State::WAIT);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToHeading(180, 700, {}, false);
    chassis.correctAt180({"front", "left"});
    chassis.moveToPoint(48, 3, 1600, {.forwards = false, .maxSpeed = 70}, true);
    chassis.waitUntil(25);
    holder.moveToState(HolderNamespace::State::HOLD);
    
    chassis.turnToHeading(180, 600,{}, false);
    chassis.correctAt180({"left"});
    chassis.turnToPoint(70, 0, 1000, {}, false);
    chassis.moveToPoint(52, 0, 1000, {}, false);
    chassis.turnToHeading(90, 1000, {}, false);

    conveyor.moveToState(ConveyorNamespace::State::STOP);
    arm.moveToState(ArmNamespace::State::UP, 300);
    pros::delay(300);
    arm.moveToState(ArmNamespace::State::DOWN);
    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToPoint(24, -24, 1000,{}, false);
    chassis.moveToPoint(24, -24, 1000, {}, false);

    
    // chassis.turnToPoint(65,-26, 700, {.forwards = false},false);
    
    // chassis.moveDistance(-36, 1200, {.forwards = false, .maxSpeed = 80}, true);
    // chassis.waitUntil(28);
    // holder.moveToState(HolderNamespace::State::HOLD);
   

    // chassis.turnToHeading(335, 1000, {}, false);
    // holder.moveToState(HolderNamespace::State::RELEASE);
    // chassis.moveDistance(-34, 1000, {.forwards = false}, false);

    // chassis.correctAt0({"right"});

    // chassis.moveDistance(48, 1000, {}, false);

    // arm.moveToState(ArmNamespace::State::WAIT);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    // chassis.turnToHeading(180, 1000, {}, false);
    // chassis.correctAt180({"left"});
    // chassis.moveToPoint(48, 0, 1000, {.forwards = false, .maxSpeed = 80}, true);
    // chassis.waitUntil(15);
    // holder.moveToState(HolderNamespace::State::HOLD);
    // chassis.turnToHeading(90, 1000, {}, false);
    // chassis.moveDistance(24, 1000, {.maxSpeed = 60}, false);
    // chassis.moveDistance( -20, 1000, {.forwards = false, .maxSpeed = 60}, false);
    // chassis.moveDistance(12, 1000, {.maxSpeed = 60}, false);

    //second part
    
    // arm.moveToState(ArmNamespace::State::UP);
    // chassis.moveDistance(-10, 1000, {}, false);
    // arm.moveToState(ArmNamespace::State::DOWN);
    
    // chassis.turnToHeading(180, 1000, {}, false);
    // chassis.moveToPoint(48, 0, 1000, {.forwards = false}, false);
    // holder.moveToState(HolderNamespace::State::HOLD);
    

    // chassis.turnAndMoveToPoint(24, -24, 1000, {},false); 
    // chassis.turnToPoint(0, 0, 1000, {}, false);
    // chassis.waitUntilDone();

    // chassis.moveToPoint(-48, -48, 1000, {}, false);
    

    // chassis.turnAndMoveToPoint(- 48,-60, 1000, {}, false);

    // chassis.turnAndMoveToPoint(- 60, -48, 1000, {}, false);

    // chassis.turnToHeading(90, 1000, {}, false);

    // holder.moveToState(HolderNamespace::State::HOLD);

    // chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    // arm.moveToState(ArmNamespace::State::WAIT);

    





}