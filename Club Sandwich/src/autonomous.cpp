#include "autonomous.h"

using namespace pros;

void printData() {
    lcd::clear_line(0);
    switch(autonomousSelected) {
        case 0:
            lcd::print(0, "Auton Selected: Standby");
            break;
        case 1:
            lcd::print(0, "Auton Slected: Left");
            break;
        case 2:
            lcd::print(0, "Auton Selected: Right");
            break;
        case 3:
            lcd::print(0, "Auton Selected: Programming Skills");
            break;
    }
    lcd::clear_line(1);
}

void lcdAutonSelect() {
    autonomousSelected++;
    if (autonomousSelected > 3) { autonomousSelected = 0; }
    printData();
}

void lcdAllianceSelect() {
    if (alliance == RED_ID) {
        alliance = BLUE_ID;
        lcd::set_background_color(0, 0, 255);
    } else if (alliance == BLUE_ID) {
        alliance = RED_ID;
        lcd::set_background_color(255, 0, 0);
    }
    printData();
}

void executeAutonomous() {
    switch (autonomousSelected) {
        case 0:
            break;
        case 1:
            leftAuton();
            break;
        case 2:
            rightAuton();
            break;
        case 3:
            skills();
            break;
    }
}

void leftAuton() {

}

void rightAuton() {

}

void skills() {

}