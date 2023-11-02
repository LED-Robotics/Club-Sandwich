#include "teleop_functions.h"
#include "controls.h"

using namespace pros;

double turnVar;
double straightVar;

void teleopDrive() {
    turnVar = (double)master.get_analog(ANALOG_RIGHT_X);//
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
    }

    //Pos. values for right turn relative, Neg. for left relative
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
    intakeVar=master.get_digital(E_CONTROLLER_DIGITAL_L2);
    outtakeVar=master.get_digital(E_CONTROLLER_DIGITAL_R2);
    pistonVarOut=master.get_digital(E_CONTROLLER_DIGITAL_UP);
    pistonVarIn=master.get_digital(E_CONTROLLER_DIGITAL_DOWN);

    if(intakeVar==true && outtakeVar==false){
        Intake=127;
    }
    else if(pistonVarOut==true){//Piston Out, Intake Extended
        intakePiston.set_value(true);
    }
    else if(intakeVar==false && outtakeVar==true){
        Intake=-127;
    }
    else if(pistonVarIn==true){//Piston In, Intake Internal
        intakePiston.set_value(false);
    }
    else{
        Intake=0;
    }

}

bool Catapult=catapultPrime.get_value();
bool PrimeShoot=master.get_digital(E_CONTROLLER_DIGITAL_A);
double catapultSpeed;

void teleopCatapult() {
    //Have Button to prime, STOP at limit switch, and fire at a button
    if(PrimeShoot==1){
        Catapult=60;
    }
    else{
        catapult=0;
    }
}

// void teleopElevate() {

// }


//For drive, turning controlled by right sitck, left stick for forward and backward
//Turning, reverse drive value to make spin
//drive y left stick
//drive x right stick
//left, right is the positive