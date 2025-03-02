#pragma once
#include "components.hpp"

void skills() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-62.5, 0, 90);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    pros::delay(300);

    chassis.moveDistance(14.5, 1000, {}, false);

    chassis.turnAndMoveToPoint(-48, -24, 1000, {.forwards = false}, false);
    chassis.waitUntil(26);

    holder.moveToState(HolderNamespace::State::HOLD);
    pros::delay(100);

    chassis.turnAndMoveToPoint(-24, -24, 1000, {.maxSpeed = 70}, false);

    chassis.turnAndMoveToPoint(0, 0, 1000, {}, false);

    chassis.turnAndMoveToPoint(24, -24, 1000, {}, false);

    arm.moveToState(ArmNamespace::State::WAIT);

    chassis.turnAndMoveToPoint(24, -48, 1000, {}, false);

    chassis.turnAndMoveToPoint(0, -60, 1000, {}, false);

    arm.moveToState(ArmNamespace::State::UP, 500);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    arm.moveToState(ArmNamespace::State::UP, 500);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    chassis.turnAndMoveToPoint(48, -60, 1000, {}, false);
    chassis.turnAndMoveToPoint(60, -48, 1000, {}, false);

    chassis.turnAndMoveToPoint(48, -48, 1000, {}, false);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveDistance(20, 1000, {}, false);

    chassis.turnAndMoveToPoint(48, 0, 1000, {.forwards = false}, false);

    chassis.turnAndMoveToPoint(24, 24, 1000, {}, false);

    chassis.turnAndMoveToPoint(24, 48, 1000, {}, false);

    chassis.turnAndMoveToPoint(-60, 28, 2000, {}, false);

    chassis.turnAndMoveToPoint(-48, 60, 1000, {}, false);

    chassis.turnToHeading(135, 1000, {}, false);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    arm.moveToState(ArmNamespace::State::WAIT);

    chassis.turnAndMoveToPoint(-24, 24, 1000, {}, false);

    chassis.turnAndMoveToPoint(0, 60, 1000, {}, false);

    arm.moveToState(ArmNamespace::State::UP, 500);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    arm.moveToState(ArmNamespace::State::WAIT);
    chassis.moveDistance(10, 1000, {}, false);

    arm.moveToState(ArmNamespace::State::UP, 500);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    chassis.moveToPoint(48, 48, 1000, {}, false);

    chassis.moveToPoint(48, 60, 1000, {}, false);

    chassis.turnAndMoveToPoint(48, 0, 1000, {}, false);

    chassis.turnAndMoveToPoint(62.5, 0, 1000, {.forwards = false}, false);

    chassis.turnAndMoveToPoint(60, 24, 1000, {.forwards = false}, false);

    chassis.turnAndMoveToPoint(60, 48, 1000, {}, false);

    chassis.turnAndMoveToPoint(48, 48, 1000, {}, false);

    chassis.turnToHeading(-135, 1000, {}, false);

    chassis.moveDistance(-10, 1000, {}, false);

    chassis.turnAndMoveToPoint(-48, 24, 2000, {}, false);

    chassis.turnAndMoveToPoint(-24, -48, 1000, {}, false);

    chassis.turnAndMoveToPoint(-60, -48, 1000, {}, false);

    chassis.turnAndMoveToPoint(-48, -60, 1000, {}, false);

    chassis.turnToHeading(45, 1000, {}, false);

    chassis.moveDistance(-10, 1000, {.forwards = false}, false);

    hanger.moveToState(HolderNamespace::State::HOLD);

    chassis.turnAndMoveToPoint(-18, -18, 1000, {}, false);
}