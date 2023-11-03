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

void teleopIntake() {
    intakeVar = master.get_digital(E_CONTROLLER_DIGITAL_L2);
    outtakeVar = master.get_digital(E_CONTROLLER_DIGITAL_R2);
    pistonVarOut = master.get_digital(E_CONTROLLER_DIGITAL_UP);
    pistonVarIn = master.get_digital(E_CONTROLLER_DIGITAL_DOWN);

    if(intakeVar && !outtakeVar){
        intake.move(127);
    }
    else if(pistonVarOut){//Piston Out, intake Extended
        intakePiston.set_value(true);
    }
    else if(!intakeVar && outtakeVar){
        intake.move(-127);
    }
    else if(pistonVarIn){//Piston In, intake Internal
        intakePiston.set_value(false);
    }
    else{
        intake.move(0);
    }

}

bool priming = false;
bool firing = false;

controller_digital_e_t prime = DIGITAL_A;
controller_digital_e_t shoot = DIGITAL_B;

// have button to prime, stop at limit switch, and fire on a different button
void teleopCatapult() {
    bool primed = !catapultPrime.get_value(); // check if primed
    if(master.get_digital(prime) && !firing) priming = true;  // start priming
    if(priming) {
        // move if not at limit switch
        if(!primed) catapult.move(60);
        else catapult.move(0);
    }
    if(master.get_digital(shoot) && primed) {
        // if limit switch is hit and shoot button is pressed
        priming = false;
        firing = true;
        // move with encoder (tune this)
        catapult.move_relative(500, 500);
    }
    if(!priming && !firing) {
        // chill
        catapult.move(0);
    }
}

// void teleopElevate() {

// }


//For drive, turning controlled by right sitck, left stick for forward and backward
//Turning, reverse drive value to make spin
//drive y left stick
//drive x right stick
//left, right is the positive