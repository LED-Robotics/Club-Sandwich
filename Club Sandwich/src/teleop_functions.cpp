#include "teleop_functions.h"
#include "constants.h"

using namespace pros;

void teleopDrive() {
    double completeSpeedLeft = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) *.89 + master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X) * .69;
    double completeSpeedRight = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) *.89 - master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X) * .69;

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

void teleopFredwheel() {
    if (master.get_digital(E_CONTROLLER_DIGITAL_A) || master.get_digital(E_CONTROLLER_DIGITAL_B)) {
        if (master.get_digital(E_CONTROLLER_DIGITAL_A)) {
            fredwheel.move((int32_t)(127.0));
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_B)) {
            fredwheel.move((int32_t)(-127.0));
        } else {
            fredwheel.move((int32_t)(0.0));
        }
    } else {
        if (partner.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) {
            fredwheel.move(E_CONTROLLER_ANALOG_LEFT_Y);
        } else {
            fredwheel.move((int32_t)(0.0));
        }
    }
}

void teleopCling() {
    if (master.get_digital(E_CONTROLLER_DIGITAL_Y) || master.get_digital(E_CONTROLLER_DIGITAL_X)) {
        climb.move((int32_t)((master.get_digital(E_CONTROLLER_DIGITAL_Y) - master.get_digital(E_CONTROLLER_DIGITAL_X))*127.0));
    } else {
        
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

    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
        pneumaticLeft.set_value(!pneumaticOut);
        pneumaticOut != pneumaticOut;
    }
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
        pneumaticRight.set_value(!pneumaticOut);
        pneumaticOut != pneumaticOut;
    }
}