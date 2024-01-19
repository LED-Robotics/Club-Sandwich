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
        case 0:
            //Push Triballs to goal
            a_ChassisDrive(12.0);
            a_ChassisTurn(10.0);
            a_ChassisDrive(6.0);
            //Bash Triballs into goal
            delay(200);
            a_ChassisDrive(-1.0);
            delay(200);
            a_ChassisDrive(5.0);
            delay(200);
            //Back chassis into load zone
            a_ChassisDrive(-4.5);
            a_ChassisTurn(10.0);
            a_ChassisDrive(-1.0);
            //Fredwheel
            // a_FredwheelGoBurr(127.0);
            // delay(27500); //27.5 seconds of pure fredwheel power
            // a_FredwheelGoBurr(0.0);
            delay(3000);  //Comment when using flywheel
            //Drive to center and push Triballs over
            a_ChassisDrive(2.0);
            a_ChassisTurn(5.0);
            a_ChassisDrive(29.0);
            delay(200);
            // a_PneumaticFlexzLeft(true);
            // a_PneumaticFlexzRight(true);
            a_ChassisTurn(-9.1);
            a_ChassisDrive(43.5);
            // a_PneumaticFlexzLeft(false);
            // a_PneumaticFlexzRight(false);
            delay(100);
            a_ChassisDrive(40.0);
            a_ChassisTurn(-41.2);
            delay(200);
            a_ChassisDrive(20.0);
            a_ChassisTurn(45.0);
            a_FredwheelGoBurr(40.0);
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
    while (true) {
        a_FredwheelGoBurr(127.0);
    }
}