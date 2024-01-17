#include "autonomous.h"
#include "autonomous_functions.h"
#include <math.h>
// using namespace pros;

void printData() {
    pros::lcd::clear_line(0);
    switch(autonomousSelected) {
        case 0:
            pros::lcd::print(0, "Auton Selected: Standby");
            break;
        case 1:
            pros::lcd::print(0, "Auton Slected: Right Auton");
            break;
        case 2:
            pros::lcd::print(0, "Auton Selected: Left Auton");
            break;
        case 3:
            pros::lcd::print(0, "Auton Selected: Programming Skills");
            break;
    }
    pros::lcd::clear_line(1);
}

void lcdAutonSelect() {
    autonomousSelected++;
    if (autonomousSelected > 3) { autonomousSelected = 0; }
    printData();
}

void lcdAllianceSelect() {
    if (alliance == RED_ID) {
        alliance = BLUE_ID;
        pros::lcd::set_background_color(0, 0, 255);
    } else if (alliance == BLUE_ID) {
        alliance = RED_ID;
        pros::lcd::set_background_color(255, 0, 0);
    }
    printData();
}

void executeAutonomous() {
    switch (autonomousSelected) {
        case 0:
            break;
        case 1:
            rightWP();//RIGHT
            break;
        case 2:
            leftWP();//LEFT
            break;
        case 3:
            skills();
            break;
    }
}

void rightWP(){
    chassis->driveToPoint({2.25_ft, 0.0_ft});
    intakePiston.set_value(true);
    intake.controllerSet(-1.0);
    pros::delay(1250);
    intake.controllerSet(0.0);
    chassis->setState({0_ft, 0_ft, 0_deg});
    chassis->driveToPoint({0.5_ft, -1.75_ft});
    intake.controllerSet(1.0);
    pros::delay(500);
    intake.controllerSet(0.0);
    chassis->turnAngle(120_deg);
    chassis->moveDistance(1.5_ft);
    intake.controllerSet(-1.0);
    pros::delay(750);
    intake.controllerSet(0.0);
    chassis->moveDistance(-0.5_ft);
    chassis->turnAngle(-55_deg);
    chassis->moveDistance(1.25_ft);
    intake.controllerSet(1.0);
    pros::delay(500);
    intake.controllerSet(0.0);
    chassis->turnAngle(90_deg);
    intake.controllerSet(-1.0);
    pros::delay(800);
    intake.controllerSet(0.0);
    intakePiston.set_value(false);
    chassis->moveDistance(-0.5_ft);
    chassis->turnAngle(175_deg);
    chassis->moveDistance(-1.75_ft);
}

void leftWP(){
    intakePiston.set_value(true);
    chassis->moveDistance(2.5_ft);//Forward to side of goal
    chassis->turnAngle(45_deg);//Turn to align with goal//move up to goal
    intake.controllerSet(-1.0);
    pros::delay(1250);          //Outtake
    intake.controllerSet(0.0);
    intakePiston.set_value(false);
    chassis->moveDistance(-0.5_ft);
    chassis->turnAngle(175_deg);
    chassis->moveDistance(-1.5_ft);
    // chassis->moveDistance(1.0_ft);
    // chassis->moveDistance(-1.0_ft);
    // chassis->moveDistance(1.0_ft);
    // chassis->turnAngle(-45_deg);
    // chassis->moveDistance(-2.0_ft);
    // intakePiston.set_value(true);
    // chassis->turnAngle(90_deg);
    // chassis->moveDistance(-1.0_ft);
}

void skills() {
    // autonTare();
    flyWheel.controllerSet(1);
    pros::delay(30000);
    //After all balls launched, turn robot and drive to other side.
    //curve around the mid extruding pole and slowly curve the robot into the balls and into the net
    //If you have time, create a movement function to return to the elevation pole and elevate.
    chassis->moveDistance(-0.25_ft);
    chassis->turnAngle(60_deg);
    intakePiston.set_value(true);
    chassis->moveDistance(-1.0_ft);
    chassis->turnAngle(-15_deg);
    chassis->moveDistance(-6.5_ft);
    intakePiston.set_value(false);
    chassis->turnAngle(120_deg);
    chassis->moveDistance(2.0_ft);
    chassis->turnAngle(60_deg);
    chassis->moveDistance(-2.0_ft);
}