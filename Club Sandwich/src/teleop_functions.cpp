#include "teleop_functions.h"
#include "constants.h"

using namespace pros;

void teleopDrive() {
    if (bashMode) {
        turnVar = (double)master.get_analog(ANALOG_RIGHT_X)*-.85;//   
    } else {
        turnVar = (double)master.get_analog(ANALOG_RIGHT_X)*.85;//
    }
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

    if (master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
    	bashMode = false;
    } else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
		bashMode = true;
	}

    if (bashMode) {
        //Bash Mode! (front is back)
        driveBLeft.move((int32_t)(-completeSpeedLeft));
        driveFLeft.move((int32_t)(-completeSpeedLeft));
        driveBRight.move((int32_t)(-completeSpeedRight));
        driveFRight.move((int32_t)(-completeSpeedRight));
    } else {
        //Standard drive (front is front)
        driveBLeft.move((int32_t)(completeSpeedLeft));
        driveFLeft.move((int32_t)(completeSpeedLeft));
        driveBRight.move((int32_t)(completeSpeedRight));
        driveFRight.move((int32_t)(completeSpeedRight));
    }
}

void teleopCatapult() {
    //One of two modes (determined by IFs)
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
        automaticPrime = false;
    } else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
       	catapultLeft.move(127);
        catapultRight.move(127);
        delay(100);
        automaticPrime = true;
    }

    if (!automaticPrime) {
        if (!master.get_digital(E_CONTROLLER_DIGITAL_A)) {
            catapultLeft.move(127*.2);
            catapultRight.move(127*.2);
        } else {
            catapultLeft.move(master.get_digital(E_CONTROLLER_DIGITAL_A)*127*.85);
            catapultRight.move(master.get_digital(E_CONTROLLER_DIGITAL_A)*127*.85);
        }

        loading = false; //The value remains true to prevent errors since loading is no longer tracked
    } else {
        //Button cannot be pressed while priming
        //Button necessary to prime and launch. In the case the limit switch or other functions fail.
        if (!catapultPrimeLeft.get_value() && !catapultPrimeRight.get_value()) {
            catapultLeft.move(127);
            catapultRight.move(127);
            loading = true;
        } else if (!master.get_digital(E_CONTROLLER_DIGITAL_A)) {
            catapultLeft.brake();
            catapultRight.brake();
            loading = false;
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_A) && !loading) {
            catapultLeft.move(127);
            catapultRight.move(127);
            delay(300);  //Fine Tune!
            catapultLeft.move(0);
            catapultRight.move(0);
        }
    }
}

void teleopPneumaticFlexz() {
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
        pneumaticLeft.set_value(false);
        pneumaticRight.set_value(false);
    }

    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
        pneumaticLeft.set_value(true);
        pneumaticRight.set_value(true);
    }
}