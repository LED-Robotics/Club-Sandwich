#include "autonomous_functions.h"

void a_ChassisDrive(double power, double millis) {
    drivetrainLeft.move((int32_t)power);
    drivetrainRight.move((int32_t)power);
    delay(millis);
    drivetrainLeft.brake();
    drivetrainRight.brake();
    delay(50);
}

void a_ChassisTurn(double power, double angle) {
    gyro.reset();
    if (angle > 0.0) {
        while(gyro.get_value() < (angle - angleDeadzone)) {
            drivetrainLeft.move((int32_t)power);
            drivetrainRight.move((int32_t)-power);
        }
    } else {
        while(gyro.get_value() > (angle + angleDeadzone)) {
            drivetrainLeft.move((int32_t)-power);
            drivetrainRight.move((int32_t)power);
        }
    }
    drivetrainLeft.brake();
    drivetrainRight.brake();
    delay(50);
}

void a_FlywheelGoBurr(double speed) {
    flywheel.move(speed);
}

void a_PneumaticFlexzLeft(bool flex) {
    pneumaticLeft.set_value(flex);
}

void a_PneumaticFlexzRight(bool flex) {
    pneumaticRight.set_value(flex);
}