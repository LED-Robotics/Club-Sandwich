#include "autonomous.h"
#include "autonomous_functions.h"
// using namespace pros;

void printData() {
    pros::lcd::clear_line(0);
    switch(autonomousSelected) {
        case 0:
            pros::lcd::print(0, "Auton Selected: Standby");
            break;
        case 1:
            pros::lcd::print(0, "Auton Slected: Left");
            break;
        case 2:
            pros::lcd::print(0, "Auton Selected: Skills");
            break;
        case 3:
            pros::lcd::print(0, "Auton Selected: Programming Skills");
            break;
    }
    pros::lcd::clear_line(1);
}

void lcdAutonSelect() {
    autonomousSelected++;
    if (autonomousSelected > 2) { autonomousSelected = 0; }
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
            leftWP();
            break;
        case 2:
            skills();
            break;
        case 3:
            leftSP();
            break;
    }
}

void leftWP() {
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
    chassis->turnAngle(-20_deg);
    chassis->moveDistance(0.3_ft);
    intake.controllerSet(-103);
    pros::delay(850);
    chassis->moveDistance(-1.1_ft);
    autonTare();
    intakePiston.set_value(true);
    intake.controllerSet(1.0);
    autonTare();
    chassis->driveToPoint({0.125_ft,-4_ft});
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

void leftSP() {//Shoot ball over to your own net, spin and hit elevation bar
//     // autonDrive(24.0);
//     // autonDrive(12.0);
// //     autonTurn(65);//90 DEGREES!!! TRISTAN IS FUCKING RETARDED
//     catapult.move(127);
//     catapult2.move(127);
//     delay(500);//fine tune
//     catapult.move(0);
//     catapult2.move(0);
//     delay(500);
//     intake.move(127);
//     autonTurn(-45);//fine tune
//     delay(500);
//     autonDrive(-48);//fine tune
//     delay(500);
//     autonTurn(65);
//     delay(500);
//     catapult.move(127);
//     catapult2.move(127);
//     delay(500);//fine tune
//     catapult.move(0);
//     catapult2.move(0);

//     autonTurn(-65);
}

void rightWP(){

}
void rightSP(){

}
void skills() {
    thunker.controllerSet(1.0);
    catapult2.controllerSet(1.0);
}