#include "autonomous.h"
#include "autonomous_functions.h"
#include <math.h>
// using namespace pros;                                                                                                                        Pineapples

void printData() {
    pros::lcd::clear_line(0);
    switch(autonomousSelected) {
        case 0:
            pros::lcd::print(0, "Auton Selected: Standby");
            break;
        case 1:
            pros::lcd::print(0, "Auton Selected: Right Auton");
            break;
        case 2:
            pros::lcd::print(0, "Auton Selected: Right Guarantee");
            break;
        case 3:
            pros::lcd::print(0, "Auton Selected: Left Auton");
            break;
        case 4:
            pros::lcd::print(0, "Auton Selected: Left Auto WP");
            break;
        case 5:
            pros::lcd::print(0, "Auton Selected: Programming Skills");
            break;

    }
    pros::lcd::clear_line(1);
}

void lcdAutonSelect() {
    autonomousSelected++;
    if (autonomousSelected > 5) { autonomousSelected = 0; }
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
            right3Pt();
            break;
        case 2:
            rightAutonGuarantee();
            break;
        case 3:
            leftAuton();
            break;
        case 4:
            leftAutonWP();
            break;
        case 5:
            skills();
            break;
    }
}

void right3Pt(){
    goofyAsyncs(2.25_ft);
    chassis->turnAngle(17.5_deg);
    intake.controllerSet(-1.0);
    pros::delay(1000);
    intake.controllerSet(0.0);
    chassis->turnAngle(-17.5_deg);
    chassis->turnAngle(-75_deg);
    intakePiston.set_value(true);
    intake.controllerSet(1.0);
    goofyAsyncs(2.45_ft);
    pros::delay(300);
    intake.controllerSet(0.0);
    chassis->turnAngle(135_deg);
    goofyAsyncs(1.5_ft);
    intake.controllerSet(-1.0);
    pros::delay(750);
    intake.controllerSet(0.0);
    goofyAsyncs(-1.0_ft);
    chassis->turnAngle(-50_deg);
    intake.controllerSet(1.0);
    intakePiston.set_value(true);
    goofyAsyncs(2.0_ft);
    pros::delay(200);
    intake.controllerSet(0.0);
    chassis->turnAngle(100_deg);
    intake.controllerSet(-1.0);
    pros::delay(650);
    intake.controllerSet(0.0);
    intakePiston.set_value(false);
    goofyAsyncs(-0.5_ft);
    chassis->turnAngle(190_deg);
    backFlaps.set_value(true);
    goofyAsyncs(-3.0_ft);
    backFlaps.set_value(false);
    intakePiston.set_value(false);
    
}

void rightAutonGuarantee(){
    intakePiston.set_value(true);
    goofyAsyncs(2.5_ft);
    chassis->turnAngle(-45_deg);
    intake.controllerSet(-1.0);
    pros::delay(1250);        
    intake.controllerSet(0.0);
    intakePiston.set_value(false);
    goofyAsyncs(-0.5_ft);
    chassis->turnAngle(-195_deg);
    goofyAsyncs(-1.5_ft);


}

void leftAuton(){

    intakePiston.set_value(true);
    goofyAsyncs(2.5_ft);
    chassis->turnAngle(45_deg);
    intake.controllerSet(-1.0);
    pros::delay(1250);
    intake.controllerSet(0.0);
    intakePiston.set_value(false);
    goofyAsyncs(-0.5_ft);
    chassis->turnAngle(195_deg);
    goofyAsyncs(-1.5_ft);
    goofyAsyncs(1.0_ft);
    goofyAsyncs(-1.0_ft);
    goofyAsyncs(1.0_ft);
}

void leftAutonWP(){
    backFlaps.set_value(true);//og
    pros::delay(250);//og
    chassis->turnAngle(-30_deg);//og
    backFlaps.set_value(false);//og
    pros::delay(500);//og
    goofyAsyncs(0.75_ft);//og
    chassis->turnAngle(-16_deg);//og
    goofyAsyncs(2.5_ft);//og
    intakePiston.set_value(true);//og

}

void skills() {
    // autonTare();
    flyWheel.controllerSet(1.0);
    pros::delay(30000);
    flyWheel.controllerSet(0.0);
    goofyAsyncs(-0.5_ft);
    chassis->turnAngle(60_deg);
    goofyAsyncs(-1.0_ft);
    chassis->turnAngle(-22_deg);
    intakePiston.set_value(true);
    goofyAsyncs(-6.0_ft);
    intakePiston.set_value(false);
    chassis->turnAngle(-45_deg);
    goofyAsyncs(-3.0_ft);
    chassis->turnAngle(-45_deg);
    goofyAsyncs(-2.0_ft);
    goofyAsyncs(1.0_ft);
    goofyAsyncs(-1.0_ft);
    goofyAsyncs(0.8_ft);
    chassis->turnAngle(150_deg);
    goofyAsyncs(3.0_ft);
    backFlaps.set_value(true);
    chassis->turnAngle(-30_deg);
    goofyAsyncs(-1.5_ft);
    chassis->turnAngle(15_deg);
    goofyAsyncs(-2.0_ft);
    goofyAsyncs(2.5_ft);
    goofyAsyncs(-3.0_ft);
    master.print(1, 0, "DONE END TIME");


    //1/10th of a time auton
    // chassis->turnAngle(-50_deg);
    // chassis->moveDistance(-0.5_ft);
    // chassis->turnAngle(60_deg);
    // chassis->moveDistance(-2.0_ft);
}