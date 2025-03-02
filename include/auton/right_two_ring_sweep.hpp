#pragma once
#include "components.hpp"

void right_two_rings_sweep() {
    chassis.setPose(-55.5, -24, -90);

    chassis.moveToPoint(-24, -24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(25);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    chassis.turnToHeading(180, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(24, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();

    chassis.moveDistance(-18, 1000, {.forwards = false}, false);
    chassis.waitUntilDone();
    holder.moveToState(HolderNamespace::State::RELEASE);

    // conveyor.moveToState(ConveyorNamespace::State::STOP);

    chassis.turnToHeading(-110, 1000, {}, false);
    chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveToPoint(-57, -61, 1500, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.turnToHeading(135, 1000);
    chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::RELEASE);


    chassis.turnToPoint(0, -48, 1000, {}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(30, 1000, {.maxSpeed = 70}, false);

    chassis.turnToHeading(-90, 1000);
    //chassis.turnToHeading(-120, 2000, {}, false);

}
