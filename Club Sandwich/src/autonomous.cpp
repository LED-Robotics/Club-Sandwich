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
    lcd::set_text(4, "FRED     \\   /       FRED");
    lcd::set_text(5, "   FRED > o w o < FRED   ");
    lcd::set_text(6, "- - - - - - - - - - - - -");
    lcd::set_text(7, "- - - - - - - - - - - - -");
    
    switch (autonomousSelected) {
        case 0:
            lcd::print(2, "Autonomous Selected: Standby. ");
            break;
        case 1:
            lcd::print(2, "Autonomous Selected: Left     ");
            break;
        case 2:
            lcd::print(2, "Autonomous Selected: Right    ");
            break;
        case 3:
            lcd::print(2, "Autonomous Selected: Skills!!!");
            lcd::print(3, "See RSC2 for Preloads         ");
            break;
    }

    if (allianceSelected > 1) {
        switch (alliance == BLUE_ID) {
            case true:
                lcd::set_text_color(255,70,255); //Purple
                lcd::clear_line(4);
                lcd::print(4, "BLUE Alliance!           ");
                lcd::set_background_color(0, 0, 255); //Blue
                break;
            case false:
                lcd::set_text_color(34, 255, 76); //Green
                lcd::clear_line(4);
                lcd::print(4, "RED Alliance!            ");
                lcd::set_background_color(255, 0, 0); //Red
                break;
        }
    }

    if (allianceSelected < 1) {
        lcd::set_text_color(255, 255, 255);
        lcd::set_background_color(0, 0, 0);
    }

    if (funButtonPressed) {
        lcd::print(4, "          -   -          ");
        lcd::print(6, "L           E          D");
        lcd::print(7, "LIGHT     IT     UP ! ! !");
        funButtonPressed = false;
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
        //Orin Autonomous
        case 0:
            chassis->moveDistance(4.0_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(-70.0_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(17.0_in);
            chassis->turnAngle(45.0_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(5.75_in);
            chassis->waitUntilSettled();
            chassis->moveDistance(-6.0_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(135.0_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(30_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(-45.0_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(90.0_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(-45_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(25.0_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(-45_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(22.0_in);
            chassis->waitUntilSettled();
            chassis->moveDistance(-10_in);
            chassis->waitUntilSettled();
            chassis->moveDistance(10_in);
            chassis->waitUntilSettled();
            chassis->moveDistance(-5_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(-90_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(40_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(90_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(40_in);
            chassis->waitUntilSettled();
            chassis->turnAngle(90_deg);
            chassis->waitUntilSettled();
            chassis->moveDistance(20_in);
            chassis->waitUntilSettled();
            chassis->waitUntilSettled();
            chassis->waitUntilSettled();
            chassis->waitUntilSettled();
            a_Tare();
            //Orin Autonomous

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
    //Orin Autonomous
        chassis->moveDistance(28_in);
        chassis->turnAngle(40.0_deg);
        chassis->moveDistance(-7_in);
        chassis->moveDistance(11_in);
        // chassis->turnAngle(-43.0_deg);
        // chassis->moveDistance(-36_in);
        // chassis->turnAngle(-48.0_deg);
        // chassis->moveDistance(-42_in);  
        a_Tare();    
}

void rightAuton() {
        chassis->moveDistance(28_in);
    chassis->turnAngle(40.0_deg);
    chassis->moveDistance(-7_in);
    chassis->moveDistance(11_in);
    // chassis->turnAngle(-43.0_deg);
    // chassis->moveDistance(-36_in);
    // chassis->turnAngle(-48.0_deg);
    // chassis->moveDistance(-42_in);
    chassis->waitUntilSettled();
    a_Tare();
}

void skills() {
    //driveToPoint({0.0_ft, 0.0ft});
    //turnAngle(0.0_deg);
    a_FredIntakeGoBurr(127.0);
    delay(27500); //27.5 Seconds of full Fredwheel

    chassis->moveDistance(4.0_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(-70.0_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(17.0_in);
    chassis->turnAngle(45.0_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(5.75_in);
    chassis->waitUntilSettled();
    chassis->moveDistance(-6.0_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(135.0_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(30_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(-45.0_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(90.0_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(-45_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(25.0_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(-45_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(22.0_in);
    chassis->waitUntilSettled();
    chassis->moveDistance(-10_in);
    chassis->waitUntilSettled();
    chassis->moveDistance(10_in);
    chassis->waitUntilSettled();
    chassis->moveDistance(-5_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(-90_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(40_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(90_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(40_in);
    chassis->waitUntilSettled();
    chassis->turnAngle(90_deg);
    chassis->waitUntilSettled();
    chassis->moveDistance(20_in);
    chassis->waitUntilSettled();
    chassis->waitUntilSettled();
    chassis->waitUntilSettled();
    chassis->waitUntilSettled();
    a_Tare();
}