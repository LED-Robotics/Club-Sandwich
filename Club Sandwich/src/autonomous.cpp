#include "autonomous.h"

using namespace pros;

//INITIALIZE
//Print Auton Selection
void printData(bool funButtonPressed) {
    lcd::clear_line(0);
    switch (autonomousSelected) {
        case 0:
            lcd::print(0, "Autonomous Selected: Standby. . .");
            break;
        case 1:
            lcd::print(0, "Autonomous Selected: Long Auton.");
            break;
        case 2:
            lcd::print(0, "Autonomous Selected: Short Auton.");
            break;
        case 3:
            lcd::print(0, "Autonomous Selected: Skills!!!");
    }

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

    if (funButtonPressed) {
        lcd::clear_line(6);
        lcd::clear_line(7);
        lcd::clear_line(3);
        lcd::print(3, "Fun Pressed Count: " + lcdFunButtonCount);
    }
}

//LCD 0
void lcdAutonSelect() {
    autonomousSelected++;
    if (autonomousSelected > 3) { autonomousSelected = 0; } //Cycle
    printData(false);
}

//LCD 1
void lcdFunButton() {
    lcdFunButtonCount++;
    lcd::print(6, "L     E     D");
    lcd::print(7, "LIGHT     IT     UP ! ! !");
    
    //The only "for" statement here.
    for (int i = 0; i < 7; i++) {
        lcd::set_text_color(0, 0, 0); //Black
        lcd::set_background_color(34, 255, 76); //Green
        delay(100);
        lcd::set_text_color(255, 255, 255); //White
        lcd::set_background_color(255, 70, 255); //Purple
        delay(100);
    }

    if (alliance == BLUE_ID && allianceSelected) {
        lcd::set_text_color(255,70,255); //Purple
        lcd::set_background_color(0, 0, 255); //Blue
    } else if (alliance == RED_ID && allianceSelected) {
        lcd::set_text_color(34, 255, 76); //Green
        lcd::set_background_color(255, 0, 0); //Red
    } else {
        lcd::set_text_color(0, 0, 0); //Black
        lcd::set_background_color(255, 255, 255); //White
    }
    printData(true);
}

//LCD 2
void lcdAllianceSelect() {
    //Set & Swap Alliance Color
    if (alliance == RED_ID) {
        alliance = BLUE_ID;
    } else if (alliance == BLUE_ID) {
        alliance = RED_ID;
    }
    allianceSelected = true;
    printData(false);
}


//EXECUTION
void executeAutonomous() {
    switch (autonomousSelected) {
        case 0:
            break;
        case 1:
            longAuton();
            break;
        case 2:
            shortAuton();
            break;
        case 3:
            skills();
            break;
    }
}

void longAuton() {

}

void shortAuton() {

}

void skills() {

}