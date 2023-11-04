#include "teleop_functions.h"
#include "controls.h"

using namespace pros;

double driveX;
double driveY;

void teleopDrive() {
    // store our raw joystick values
    driveX = (double)master.get_analog(DRIVE_X) / 127.0;  // /127 to push value between -1.0 and 1.0
    driveY = (double)master.get_analog(DRIVE_Y) / 127.0;

    // zero out axes if they fall within deadzone
    if (driveX > -driveDeadzone && driveX < driveDeadzone)
        driveX = 0.0;
    if (driveY > -driveDeadzone && driveY < driveDeadzone)
        driveY = 0.0;

    // setup differential variables for arcade control
    double leftSpeedRaw = driveY + driveX;
    double rightSpeedRaw = driveY - driveX;
    // Its me
    // put speeds through a polynomial to smooth out joystick input
    // check the curve out here: https://www.desmos.com/calculator/65tpwhxyai the range between 0.0 to 1.0 is used for the motors
    // change driveCurveExtent to modify curve strength
    float leftSpeed = driveCurveExtent * pow(leftSpeedRaw, 3) + (1- driveCurveExtent) * leftSpeedRaw;
    float rightSpeed = driveCurveExtent * pow(rightSpeedRaw, 3) + (1- driveCurveExtent) * rightSpeedRaw;

    // set motors to final speeds
    backLeft.move((int32_t)(leftSpeed * 127));  // *127 to change value back to int
    frontLeft.move((int32_t)(leftSpeed * 127));
    backRight.move((int32_t)(rightSpeed * 127));
    frontRight.move((int32_t)(rightSpeed * 127));
}

bool intakeVar;
bool outtakeVar;
bool pistonVarOut;
bool pistonVarIn;
bool extendIntake;
//Its me
void teleopIntake() {
    intakeVar = master.get_digital(E_CONTROLLER_DIGITAL_L1);
    outtakeVar = master.get_digital(E_CONTROLLER_DIGITAL_R1);

    if(intakeVar && !outtakeVar){
        intake.move(127);
    }
    else if(!intakeVar && outtakeVar){
        intake.move(-127);
    }
    else if(master.get_digital_new_press(DIGITAL_A)){
        extendIntake=!extendIntake;
        intakePiston.set_value(extendIntake);
    }
    else{
        intake.move(0);
    }
}

int bottom = 0;

controller_digital_e_t shoot = DIGITAL_R2;

// have button to prime, stop at limit switch, and fire on a different button
void teleopCatapult() {
    bool primed = catapultLineSense.get_value() < 1000; // check if primed
    pros::lcd::print(3, "Dingdong: %d", primed);
    bool shooting = master.get_digital(shoot);
    if(!shooting) {//Automatic Prime
        // move if not primed
        if(!primed) {
            catapult.move(100);
            catapult2.move(100);
        }
        else {
            catapult.move(15);
            catapult2.move(15);
        }
    } else {
        catapult.move(127);
        catapult2.move(127);
    }
    pros::lcd::print(4, "Dingdonger: %d", catapult.get_voltage());
}

bool leftPlowState = false;
bool rightPlowState = false;

void teleopPlow(){
   if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) leftPlowState = !leftPlowState;
   if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) rightPlowState = !rightPlowState;
   if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
        int states = leftPlowState + rightPlowState;
        if(states < 2) {
            leftPlowState = true;
            rightPlowState = true;
        } else {
            leftPlowState = false;
            rightPlowState = false;
        }
   }
    leftPlow.move_absolute(leftPlowState ? 90 : 0, 500);
    rightPlow.move_absolute(rightPlowState ? 90 : 0, 500);
}


void teleopElevate() {

}


//For drive, turning controlled by right sitck, left stick for forward and backward
//Turning, reverse drive value to make spin
//drive y left stick
//drive x right stick
//left, right is the positive