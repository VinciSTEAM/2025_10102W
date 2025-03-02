#pragma once
#include "components.hpp"

void red_six_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);

    chassis.setPose(-53.5, 24, -90);

    chassis.moveToPoint(-24, 24, 2000, {.forwards = false, .maxSpeed = 75}, false);

    chassis.waitUntil(15);

    // holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(150);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    pros::delay(100);
    chassis.moveToPose(-7, 48, 0, 3000, {.lead = 0.3, .maxSpeed = 127}, false);

    chassis.moveToPoint(-24, 24, 1200, {.forwards = false, .maxSpeed = 100}, false);

    chassis.moveToPoint(-24, 39, 1000, {.maxSpeed = 127}, false);

    chassis.turnToHeading(-85, 1000, {.maxSpeed = 127}, false);

    chassis.moveToPoint(-54, 59, 1520, {.maxSpeed = 127}, false);
    chassis.turnToHeading(-55,1000, {.maxSpeed = 127}, false);
    chassis.moveDistance(10,3000,{.forwards = true, .maxSpeed = 100}, false);
    chassis.moveDistance(-5,3000,{.forwards = false, .maxSpeed = 100}, false);
    pros::delay(150);
    chassis.moveToPose(-48 ,24, 180, 3000, {.lead = 0.3, .maxSpeed = 127}, false);

    //intake_raiser.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPose(0,24,180, 3000, {.lead = 0.3, .maxSpeed = 127}, false);
/*  doinker.moveToState(HolderNamespace::State::HOLD);

    
    chassis.moveDistance(4, 1000, {.maxSpeed = 127}, false);

    pros::delay(200);

    chassis.moveDistance(10, 1000, {.forwards = false, .maxSpeed = 70}, false);

    chassis.turnToHeading(-180, 1000, {.maxSpeed = 100}, false);

    intake_raiser.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPoint(-35, 0, 2000, {}, false);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);*/
    
}
