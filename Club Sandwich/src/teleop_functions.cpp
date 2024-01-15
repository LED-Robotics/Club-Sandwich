#include "teleop_functions.h"
#include "controls.h"

// using namespace pros;

double driveX;
double driveY;

void teleopDrive() {
    // store our raw joystick values
    driveX = (double)master.get_analog(DRIVE_X) / 127.0;  // /127 to push value between -1.0 and 1.0
    driveY = (double)master.get_analog(DRIVE_Y) / 127.0;

    // pros::lcd::print(2, "DriveY: %f", driveY);
    // pros::lcd::print(3, "DriveX: %f", driveX);

    driveX = driveCurveExtent * pow(driveX, 3) + (1- driveCurveExtent) * driveX;
    driveY = driveCurveExtent * pow(driveY, 3) + (1- driveCurveExtent) * driveY;

    chassisModel->arcade(driveY, driveX, driveDeadzone);
    // chassisModel->tank(driveY, driveY);

    // // zero out axes if they fall within deadzone
    // if (driveX > -driveDeadzone && driveX < driveDeadzone)
    //     driveX = 0.0;
    // if (driveY > -driveDeadzone && driveY < driveDeadzone)
    //     driveY = 0.0;

    // // setup differential variables for arcade control
    // double leftSpeedRaw = driveY + driveX;
    // double rightSpeedRaw = driveY - driveX;
    // // Its me
    // // put speeds through a polynomial to smooth out joystick input
    // // check the curve out here: https://www.desmos.com/calculator/65tpwhxyai the range between 0.0 to 1.0 is used for the motors
    // // change driveCurveExtent to modify curve strength
    // double leftSpeed = driveCurveExtent * pow(leftSpeedRaw, 3) + (1- driveCurveExtent) * leftSpeedRaw;
    // double rightSpeed = driveCurveExtent * pow(rightSpeedRaw, 3) + (1- driveCurveExtent) * rightSpeedRaw;

    // // set motors to final speeds
    // backLeft.controllerSet(leftSpeed);  // *127 to change value back to int
    // frontLeft.controllerSet(leftSpeed);
    // backRight.controllerSet(rightSpeed);
    // frontRight.controllerSet(rightSpeed);
}

bool intakeVar;
bool outtakeVar;
bool pistonVarOut;
bool pistonVarIn;
bool extendIntake;
//Its me
void teleopIntake() {
    intakeVar=master.get_digital(DIGITAL_R1);
    outtakeVar=master.get_digital(DIGITAL_L1);
    pistonVarOut=master.get_digital_new_press(DIGITAL_UP);
    pistonVarIn=master.get_digital_new_press(DIGITAL_DOWN);

    if(intakeVar){
        intake.controllerSet(1.0);
    }
    else if(outtakeVar){
        intake.controllerSet(-1.0);
    }
    else{
        intake.controllerSet(0);

    }

    //SECTION FOR PNEUMATICS

    if(pistonVarOut){
        intakePiston.set_value(true);
    }
    if(pistonVarIn){
        intakePiston.set_value(false);
    }
}

int bottom = 0;

pros::controller_digital_e_t shoot = DIGITAL_R2;

// have button to prime, stop at limit switch, and fire on a different button


bool leftPlowState = false;
bool rightPlowState = false;

void teleopFlywheel(){
    bool thunkerNoThunking = master.get_digital(DIGITAL_R2);

    if(thunkerNoThunking){
        flyWheel.controllerSet(1.0);
    }
    else{
        flyWheel.controllerSet(0.0);
    }
}


void teleopFlap() {
    int flapCounter;
    int flapRetract;
    bool flap=master.get_digital(DIGITAL_LEFT);
    bool noFlap=master.get_digital(DIGITAL_RIGHT);
    if(flap){
        leftFlap.moveAbsolute(90, 100);
    }
    if(noFlap){
        leftFlap.moveAbsolute(-90, 100);
    }
}

int pneumaticOut = 0;
void teleopZoneFlapper() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        backFlapPiston.set_value(pneumaticOut % 2 == 1);
        pneumaticOut++;
    }
}


//For drive, turning controlled by right sitck, left stick for forward and backward
//Turning, reverse drive value to make spin
//drive y left stick
//drive x right stick
//left, right is the positive