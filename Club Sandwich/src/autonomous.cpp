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
            pros::lcd::print(0, "Auton Slected: Right");
            break;
        case 2:
            pros::lcd::print(0, "Auton Selected: Left");
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
            rightWP2();//RIGHT
            break;
        case 2:
            leftWP();//LEFT
            break;
        case 3:
            leftSP();
            break;
    }
}

void rightWP() {
    // autonPrime();
    // intake.move(127);
    // delay(1500);
    // intake.move(0);
    // catapult.move(127);
    // catapult2.move(127);
    // delay(750);//fine tune
    // catapult.move(0);
    // catapult2.move(0);
    // autonDrive(-4.5);
    // delay(500);
    // autonTurn(220.0);//fine tune
    // intakePiston.set_value(true);
    // autonPrime();
    // intake.move(127);
    // autonDrive(60.0);
    // intakePiston.set_value(false);
    // delay(1500);
    // intake.move(0);
    // autonDrive(-40.0);
    // autonTurn(120);
    // delay(500);
    // catapult.move(127);
    // catapult2.move(127);
    // delay(350);
    // catapult.move(0);
    // catapult2.move(0);
    // autonTurn(25);
    // delay(500);
    // autonDrive(-41.5);
    // chassis->moveDistance(1.0_ft);
    // chassis->turnAngle(90.0_deg);
    // pros::delay(2000);
    // chassis->moveDistance(2.0_ft);
    chassis->setState({0_ft, 0_ft, 0_deg});
    chassis->stop();
    chassis->waitUntilSettled();
    chassis->driveToPoint({0.5_ft, 0.0_ft});
    autonTare();
    intakePiston.set_value(true);
    chassis->driveToPoint({1.6_ft, 1.6_ft});
    autonTare();
    chassis->turnToAngle(-20_deg);
    autonTare();
    chassis->driveToPoint({0.1_ft, 0.0_ft});
    intake.controllerSet(-1.0);
    pros::delay(850);
    chassis->moveDistance(-1.1_ft);
    autonTare();
    intakePiston.set_value(true);
    intake.controllerSet(1.0);
    autonTare();
    chassis->driveToPoint({0.125_ft,-3.75_ft});
    pros::delay(500);
    intake.controllerSet(0);
    autonTare();
    chassis->driveToPoint({-0.9_ft, 1.4_ft});
    intake.controllerSet(-1.0);
    autonTare();



    // chassis->moveDistance(-0.5_ft);
    // autonTare();
    // chassis->turnAngle(-25_deg);
    // autonTare();
    // chassis->moveDistance(-1.0_ft);




}

void rightWP2(){
    // chassis->driveToPoint({0.5_ft, 0.0_ft});
    // intakePiston.set_value(true);
    // chassis->driveToPoint({2.0_ft, 1.0_ft});
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

void leftSP() {//Shoot ball over to your own net, spin and hit elevation bar
   chassis->moveDistanceAsync(2.0_ft);
   pros::delay(250);
   chassis->turnAngleAsync(45_deg);
   chassis->waitUntilSettled();
   
    // chassis->driveToPoint({2.0_ft, 2.0_ft});
}

void leftWP(){
    flyWheel.controllerSet(1);
    pros::delay(850);
    flyWheel.controllerSet(0);
    // chassis->setState({0_ft, 0_ft, 0_deg});
    autonTare();
    // chassis->driveToPoint({1_ft, 0_ft});

}
void rightSP(){

}
void skills() {
    autonTare();
    chassis->turnToPoint({1.0_ft, 0.0_ft});
}//2nd value on the X axis, first value on the Y