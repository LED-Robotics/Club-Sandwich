#include "autonomous_functions.h"

void a_Drive(double distance) {
    int speed = 100;
    double modifier = 1.0;
    if(distance < 0) speed *= -1;
    double initial = (abs(frontLeft.get_position()) * INCH_CONSTANT + abs(frontRight.get_position()) * INCH_CONSTANT) / 2;
    double current = 0.0;
    while(current < distance) {
        current = ((abs(frontLeft.get_position()) * INCH_CONSTANT + abs(frontRight.get_position()) * INCH_CONSTANT) / 2) - initial;
        modifier = 1.8 - (current / distance) * 1.5;
        if(modifier > 1.0) modifier = 1.0;

        backLeft.move(speed * modifier);
        frontLeft.move(speed * modifier);
        backRight.move(-speed * modifier);
        frontRight.move(-speed * modifier);
        delay(20);
    }
    backLeft.move(0);
    frontLeft.move(0);
    backRight.move(0);
    frontRight.move(0);
}

void a_Turn(double angle) {
    gyro.tare();
    int speed = 80;
    double modifier = 1.0;
    if(angle < 0) speed *= -1;
    double current = 0.0;
    while(current < angle) {
        current = abs(gyro.get_rotation());
        modifier = 1.8 - (current / angle) * 1.5;
        if(modifier > 1.0) modifier = 1.0;

        backLeft.move(speed * modifier);
        frontLeft.move(speed * modifier);
        backRight.move(-speed * modifier);
        frontRight.move(-speed * modifier);
        delay(20);
    }
    backLeft.move(0);
    frontLeft.move(0);
    backRight.move(0);
    frontRight.move(0);
}

void a_Intake(bool power) {
    intake.move((int32_t)power * 127);
}

void a_fireCatapult() {

}

void a_reloadCatapult() {
    catapultLeft.move(127*.7);
    catapultRight.move(127*.7);
    delay (100);
    catapultLeft.move(0);
    catapultRight.move(0);
}

        // //Button cannot be pressed while priming
        // //Button necessary to prime and launch. In the case the limit switch or other functions fail.
        // if (!catapultPrime.get_value()) {
        //     catapultLeft.move(127*.85);
        //     catapultRight.move(127*.85);
        //     loading = true;
        // }

        // if (catapultPrime.get_value() && !master.get_digital(E_CONTROLLER_DIGITAL_A)) {
        //     catapultLeft.brake();
        //     catapultRight.brake();
        //     loading = false;
        // }