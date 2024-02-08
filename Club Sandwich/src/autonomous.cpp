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
        chassis->moveDistance(25_in);
        chassis->moveDistance(-5_in);
        chassis->moveDistance(8 _in);


        w33e1.
        
        chassis->moveDistance(-9_in);
        chassis->turnAngle(45_deg);
        chassis->moveDistance(-22_in);
        chassis->turnAngle(45_deg);
        chassis->moveDistance(-32_in);

        a_Tare();    
}

void rightAuton() {

    // 1st Triball

    chassis->moveDistance(20_in);
    chassis->turnAngle(-58.0_deg);
    chassis->moveDistance(10_in);
    chassis->moveDistance(-12_in);
    chassis->moveDistance(10_in);

    // 2nd Triball
    
    chassis->moveDistance(-8.0_in);
    chassis->turnAngle(-100.0_deg);
    chassis->moveDistance(25.0_in);
    chassis->turnAngle(85_deg);
    chassis->moveDistance(12_in);
    chassis->turnAngle(130.0_deg);
    climb.move(127);
    chassis->moveDistance(25.0_in);
    chassis->turnAngle(-15_deg);
    delay(1000);
    climb.move(0);
    fredIntake.move(127);
    chassis->moveDistance(25.0_in);
    chassis->turnAngle(180_deg);
    fredIntake.move(-127);
    chassis->moveDistance(5_in);
    chassis->turnAngle(180_deg);
    chassis->moveDistance(8_in);
    chassis->waitUntilSettled();
    delay(1000);
    fredIntake.move(0);

    // 3rd Triball

    chassis->moveDistance(-45_in);
    fredIntake.move(127);
    chassis->waitUntilSettled();
    chassis->moveDistance(-15_in);
    chassis->turnAngle(-270_deg);
    chassis->moveDistance(18_in);
    chassis->turnAngle(-90_deg);
    fredIntake.move(127);
    chassis->moveDistance(-22_in);
    delay(2000);
    chassis->moveDistance(44_in);
    chassis->turnAngle(180_deg);
    fredIntake.move(-127);
    chassis->moveDistance(5_in);
    chassis->turnAngle(180_deg);
    chassis->moveDistance(8_in);
    chassis->waitUntilSettled();
    a_Tare();
}

void skills() {
    //driveToPoint({0.0_ft, 0.0ft});
    //turnAngle(0.0_deg);
    fredIntake.move(127);
    delay(33000);
    chassis->moveDistance(93_in);
    chassis->turnAngle(45_deg);
    chassis->moveDistance(30_in);
    chassis->turnAngle(45.0_deg);
    chassis->moveDistance(10_in);
    chassis->moveDistance(-10_in);
    chassis->moveDistance(12_in);
}