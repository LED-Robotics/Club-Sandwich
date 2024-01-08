#include "autonomous.h"

using namespace pros;

//INITIALIZE
//Print Auton Selection
void printData(bool funButtonPressed) {
    lcd::clear();
    lcd::set_text(0, "Hello, Team Hunter!");
	lcd::set_text(1, "Remember RULE #1: to have fun!");
    lcd::set_text(2, "- - - - - - - - - - - - -");
    lcd::set_text(3, "- - - - - - - - - - - - -");
    lcd::set_text(4, "- - - - - - - - - - - - -");
    lcd::set_text(5, "- - - - - - - - - - - - -");
    lcd::set_text(6, "- - - - - - - - - - - - -");
    lcd::set_text(7, "- - - - - - - - - - - - -");
    lcd::set_text(8, "- - - - - - - - - - - - -");
    
    switch (autonomousSelected) {
        case 0:
            lcd::print(2, "Autonomous Selected: Standby.");
            break;
        case 1:
            lcd::print(2, "Autonomous Selected: Left");
            break;
        case 2:
            lcd::print(2, "Autonomous Selected: Right");
            break;
        case 3:
            lcd::print(2, "Autonomous Selected: Catapult");
            break;
        case 4:
            lcd::print(2, "Autonomous Selected: Skills!!!");
            lcd::print(3, "Programming expertice for 1min");
            break;
    }

    if (allianceSelected > 1) {
        switch (alliance == BLUE_ID) {
            case true:
                lcd::set_text_color(255,70,255); //Purple
                lcd::clear_line(4);
                lcd::print(4, "BLUE Alliance!");
                lcd::set_background_color(0, 0, 255); //Blue
                break;
            case false:
                lcd::set_text_color(34, 255, 76); //Green
                lcd::clear_line(4);
                lcd::print(4, "RED Alliance!");
                lcd::set_background_color(255, 0, 0); //Red
                break;
        }
    }

    if (allianceSelected < 1) {
        lcd::set_text_color(255, 255, 255);
        lcd::set_background_color(0, 0, 0);
    }

    if (funButtonPressed) {
        lcd::print(6, "L           E          D");
        lcd::print(7, "LIGHT     IT     UP ! ! !");
        funButtonPressed = false;
    }
}

//LCD 0
void lcdAutonSelect() {
    autonomousSelected++;
    if (autonomousSelected > 4) { autonomousSelected = 0; } //Cycle
    printData(false);
}

//LCD 1
void lcdFunButton() {
    funButtonPressed = true;
    printData(true);
}

//LCD 2
void lcdAllianceSelect() {
    allianceSelected++;
    //Set & Swap Alliance Color
    if (alliance == RED_ID) {
        alliance = BLUE_ID;
    } else if (alliance == BLUE_ID) {
        alliance = RED_ID;
    }
    printData(false);
}


//EXECUTION
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
            onlyCatapult();
            break;
        case 4:
            skills();
            break;
    }
}

void leftAuton() {
    a_CatapultReload();
    delay(100);
    a_CatapultFire();
    a_ChassisDrive(1.0, 0.0, 0.0);
    a_ChassisTurn(28.5, 0.0, 0.0);
    a_ChassisDrive(-42.0, 0.0, 0.0);
    a_ChassisTurn(89.0, 0.0, 0.0);
}

void rightAuton() {
    a_CatapultSpeed(40.0);
    a_CatapultReload();
    a_ChassisDrive(-15.0, 0.0, 0.0);
    a_ChassisTurn(-25.0, 0.0, 0.0);
    delay(100);
    a_CatapultFire();
    a_CatapultReload();
    a_ChassisTurn(25.0, 0.0, 0.0);
    a_ChassisDrive(-8.5, 0.0, 0.0);
    a_ChassisTurn(-205.0, 0.0, 0.0);
    a_ChassisDrive(23.3, 0.0, 0.0);
    delay(100);
    a_PneumaticFlexzLeft(true);
    for (double i = 0.0; i < 4.0; i++) {
        a_ChassisDrive(1.9, 0.0, 0.0);
        a_ChassisTurn(17.0, 0.0, 0.0);
    }
    a_ChassisDrive(20.0, 0.0, 0.0);
    a_PneumaticFlexzLeft(false);
}

void onlyCatapult() {
    a_CatapultReload();
    a_CatapultFire();
}

void skills() {
    while (true) {
        a_CatapultReload();
        delay(300);
        a_CatapultFire();
    }
}
