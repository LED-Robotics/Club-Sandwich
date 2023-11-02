#include "teleop_functions.h"
#include "constants.h"

using namespace pros;

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
        }  //Pos. values for right turn relative, Neg. for left relative
    }

    if (master.get_digital_new_press(DIGITAL_UP)) {
        bashMode != bashMode;
    }

    if (bashMode) {
        //Bash Mode! (front is back)
        backLeft.move((int32_t)(-completeSpeedLeft));
        frontLeft.move((int32_t)(-completeSpeedLeft));
        backRight.move((int32_t)(-completeSpeedRight));
        frontRight.move((int32_t)(-completeSpeedRight));    
    } else {
        //Standard drive (front is front)
        backLeft.move((int32_t)(completeSpeedLeft));
        frontLeft.move((int32_t)(completeSpeedLeft));
        backRight.move((int32_t)(completeSpeedRight));
        frontRight.move((int32_t)(completeSpeedRight));
    }
}

void teleopIntake() {
    intake.move(master.get_digital(DIGITAL_L2)*127*.7 - master.get_digital(DIGITAL_R2)*127*.7);
}

void teleopCatapult() {
    //One of two modes (determined by IFs)
    if (master.get_digital_new_press(DIGITAL_DOWN)) {
       	automaticPrime != automaticPrime;
    }

    if (!automaticPrime) {
        //Catapult primes automatically, stops at limit switch, and fires at a button
        catapultLeft.move(master.get_digital(E_CONTROLLER_DIGITAL_A)*127*.6);
        catapultRight.move(master.get_digital(E_CONTROLLER_DIGITAL_A)*127*.6);
        loading = true; //The value remains true to prevent errors since loading is no longer tracked
    } else {
        //Button cannot be pressed while priming
        //Button necessary to prime and launch. In the case the limit switch or other functions fail.
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
            delay(100);  //Fine Tune!
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