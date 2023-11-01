#include "teleop_functions.h"
#include "controls.h"

using namespace pros;

double turnVar;
double straightVar;

void teleopDrive() {
    turnVar = (double)master.get_analog(ANALOG_RIGHT_X)*.75;//
    straightVar = (double)master.get_analog(ANALOG_LEFT_Y);//
    
    if (fabs(turnVar) < driveDeadzone) {
        turnVar = 0.0;
    }
    if (fabs(straightVar) < driveDeadzone) {
        straightVar = 0.0;
    }
    double completeSpeedLeft = straightVar;
    double completeSpeedRight = straightVar;//full speed for going straight/backwards
    
    if (turnVar!=0.0){//If You Want to Turn
        if(turnVar>0.0){//Right************************************//
            if(straightVar>0.0){//Going Forward
                completeSpeedRight=straightVar-fabs(turnVar);
                if(completeSpeedRight<0.0){
                    completeSpeedRight=0.0;
                }
            }
            else if(straightVar<0.0){//Going Backward
                completeSpeedRight=straightVar+fabs(turnVar);
                if (completeSpeedRight>0.0){
                    completeSpeedRight=0.0;
                }
            }
            else{
                completeSpeedLeft=fabs(turnVar);
                completeSpeedRight=-fabs(turnVar);
            }
        }
        if(turnVar<0.0){//Left**************************************//
            if(straightVar>0.0){//Going Forward
                completeSpeedLeft=straightVar-fabs(turnVar);
                if(completeSpeedLeft<0.0){
                    completeSpeedLeft=0.0;
                }
            }
            else if(straightVar<0){//Going Backwards
                completeSpeedLeft=straightVar+fabs(turnVar);
                if(completeSpeedLeft>0.0){
                    completeSpeedLeft=0.0;
                }
            }
            else{
                completeSpeedLeft=-fabs(turnVar);
                completeSpeedRight=fabs(turnVar);
            }
        }
        
              //Pos. values for right turn relative, Neg. for left relative
    }

    backLeft.move((int32_t)(completeSpeedLeft));
    frontLeft.move((int32_t)(completeSpeedLeft));
    backRight.move((int32_t)(completeSpeedRight));
    frontRight.move((int32_t)(completeSpeedRight));
}
bool intakeVar;
bool outtakeVar;
bool pistonVarOut;
bool pistonVarIn;


void teleopIntake() {
    intake.move(master.get_digital(DIGITAL_L2)*127*.7 - master.get_digital(DIGITAL_R2)*127*.7);
}

bool loading = false;

void teleopCatapult(bool buttonMode) {
    //Have Button to prime, STOP at limit switch, and fire at a button
    if (buttonMode) {
        catapultLeft.move(master.get_digital(E_CONTROLLER_DIGITAL_A)*127*.9);
        catapultRight.move(master.get_digital(E_CONTROLLER_DIGITAL_A)*127*.9);
    }

    if (!buttonMode) {
        if (!catapultPrime.get_value()) {
            catapultLeft.move(127*.85);
            catapultRight.move(127*.85);
            loading = true;
        }

        if (catapultPrime.get_value() && !master.get_digital(E_CONTROLLER_DIGITAL_A)) {
            catapultLeft.brake();
            catapultRight.brake();
            loading = false;
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_A) && !loading) {
            catapultLeft.move(127*.85);
            catapultRight.move(127*.85);
            delay(100);
            catapultLeft.move(0);
            catapultRight.move(0);
        }
    }
}

void teleopElevate() {

}


//For drive, turning controlled by right sitck, left stick for forward and backward
//Turning, reverse drive value to make spin
//drive y left stick
//drive x right stick
//left, right is the positive