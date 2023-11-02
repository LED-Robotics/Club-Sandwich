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
        
              //Pos. values for right turn relative, Neg. for left relative
    }

    backLeft.move((int32_t)(completeSpeedLeft));
    frontLeft.move((int32_t)(completeSpeedLeft));
    backRight.move((int32_t)(completeSpeedRight));
    frontRight.move((int32_t)(completeSpeedRight));
}
bool intakeVar;
bool outtakeVar;
bool extendIntake;
bool extendPlow;

void teleopIntake() {
    intakeVar=master.get_digital(E_CONTROLLER_DIGITAL_L1);
    outtakeVar=master.get_digital(E_CONTROLLER_DIGITAL_R1);
    if(intakeVar==true && outtakeVar==false){
        Intake=127;
    }
    else if(intakeVar==false && outtakeVar==true){
        Intake=-127;
    }
    else{
        Intake=0;
    }

    if(master.get_digital_new_press(DIGITAL_A)){
        extendIntake=!extendIntake;
        intakePiston.set_value(extendIntake);

    }
    if(master.get_digital_new_press(DIGITAL_Y)){
        extendPlow=!extendPlow;
        plowPiston.set_value(extendPlow);
    }

}
bool Catapult=catapultPrime.get_value();
bool PrimeShoot=master.get_digital(E_CONTROLLER_DIGITAL_R2);
double catapultSpeed;
void teleopCatapult() {
    bool shoot= master.get_digital(DIGITAL_R2);
    //Have Button to prime, STOP at limit switch, and fire at a button
    if(shoot==1){
        catapult=100;
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