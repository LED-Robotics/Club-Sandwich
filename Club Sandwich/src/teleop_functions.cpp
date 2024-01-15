#include "teleop_functions.h"
#include "constants.h"

using namespace pros;

void teleopDrive() {
    if (bashMode) {
        turnVar = (double)master.get_analog(ANALOG_RIGHT_X)*-.73;//
    } else {
        turnVar = (double)master.get_analog(ANALOG_RIGHT_X);//
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
        drivetrainLeft.move((int32_t)(-completeSpeedLeft));
        drivetrainRight.move((int32_t)(-completeSpeedRight));
    } else {
        //Standard drive (front is front)
        drivetrainLeft.move((int32_t)(completeSpeedLeft));
        drivetrainRight.move((int32_t)(completeSpeedRight));
    }
}

void teleopFlywheel() {
    if (master.get_digital(E_CONTROLLER_DIGITAL_A)) {
        flywheel.move((int32_t)(127.0));
    } else if (master.get_digital(E_CONTROLLER_DIGITAL_B)) {
        flywheel.move((int32_t)(-127.0));
    } else {
        flywheel.move((int32_t)(0.0));
    }
}

void teleopCling() {
    climb.move((int32_t)((master.get_digital(E_CONTROLLER_DIGITAL_Y) - master.get_digital(E_CONTROLLER_DIGITAL_X))*127.0));
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

    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
        pneumaticLeft.set_value(!pneumaticOut);
        pneumaticOut != pneumaticOut;
    }
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
        pneumaticRight.set_value(!pneumaticOut);
        pneumaticOut != pneumaticOut;
    }
}