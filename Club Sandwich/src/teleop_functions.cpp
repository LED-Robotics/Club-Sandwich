#include "teleop_functions.h"
#include "constants.h"

using namespace pros;

void t_CheckPartnerConnect() {
    if (partner.is_connected() && !partnerConnected) {
		partnerConnected = true;
	} else if (!partner.is_connected() && partnerConnected) {
		partnerConnected = false;
	}
}

void t_OkapiLibDrive() {
    driveX = (double)master.get_analog(DRIVE_X) / 127.0 * .9;
    driveY = (double)master.get_analog(DRIVE_Y) / 127.0; 

    driveX = driveCurveExtent * pow(driveX, 3) + (1- driveCurveExtent) * driveX;
    driveY = driveCurveExtent * pow(driveY, 3) + (1- driveCurveExtent) * driveY;

    if (master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
        bashMode = false;
    } else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
        bashMode = true;
    }

    if (bashMode) {
        chassisModel->arcade(-driveY, driveX, driveDeadzone);
    } else {
        chassisModel->arcade(driveY, driveX, driveDeadzone);
    }
}

//Deprecated 2024-01-19
// void t_Drive() {
//     double completeSpeedLeft = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) *.89 + master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X) * .69;
//     double completeSpeedRight = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) *.89 - master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X) * .69;

//     if (master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
//     	bashMode = false;
//     } else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) {
// 		bashMode = true;
// 	}

//     if (bashMode) {
//         //Bash Mode! (front is back)
//         drivetrainLeft.move((int32_t)(-completeSpeedLeft));
//         drivetrainRight.move((int32_t)(-completeSpeedRight));
//     } else {
//         //Standard drive (front is front)
//         drivetrainLeft.move((int32_t)(completeSpeedLeft));
//         drivetrainRight.move((int32_t)(completeSpeedRight));
//     }
// }

void t_Fredintake() {
    if (master.get_digital(E_CONTROLLER_DIGITAL_L2) || master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
        fredIntake.move((master.get_digital(E_CONTROLLER_DIGITAL_R2) - master.get_digital(E_CONTROLLER_DIGITAL_L2)) * 127.0); 
    } else {
        if (partner.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) {
            fredIntake.move(partner.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
        } else {
            fredIntake.move((int32_t)(0.0));
        }
    }
}

void t_Cling() {
    if (master.get_digital(E_CONTROLLER_DIGITAL_Y) || master.get_digital(E_CONTROLLER_DIGITAL_X)) {
        climb.move((int32_t)((master.get_digital(E_CONTROLLER_DIGITAL_Y) - master.get_digital(E_CONTROLLER_DIGITAL_X))*127.0));
    } else {
        climb.move((int32_t)(partner.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)*127.0));
    }
}

//Deprecated 2024-01-18
// void t_PneumaticFlexz() {
//     if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
//         pneumaticLeft.set_value(false);
//         pneumaticRight.set_value(false);
//     }

//     if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
//         pneumaticLeft.set_value(true);
//         pneumaticRight.set_value(true);
//     }

//     if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
//         pneumaticLeft.set_value(!pneumaticOut);
//         pneumaticOut != pneumaticOut;
//     }
//     if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
//         pneumaticRight.set_value(!pneumaticOut);
//         pneumaticOut != pneumaticOut;
//     }
// }