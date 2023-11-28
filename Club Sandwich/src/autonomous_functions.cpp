#include "autonomous_functions.h"

void a_Drive(double distance, double staticMod, double dynamicMod) {
    backLeft.tare_position();
    frontLeft.tare_position();
    backRight.tare_position();
    frontRight.tare_position();
    double initial = 0;
    bool backwards = false;
    if (distance < 0.0) {
        backwards = true;
    }
    distance = fabs(distance);
    int speed = 100;
    double modifier = 1.0;
    if(distance < 0) speed *= -1;
    if (distance > 12) {
        initial = (abs(frontLeft.get_position()) * INCH_CONSTANT + abs(frontRight.get_position()) * INCH_CONSTANT) / 2 -12;
    } else {
        initial = (abs(frontLeft.get_position()) * INCH_CONSTANT + abs(frontRight.get_position()) * INCH_CONSTANT) / 2;
    }
    double current = 0.0;
    while(current < distance) {
        current = ((abs(frontLeft.get_position()) * INCH_CONSTANT + abs(frontRight.get_position()) * INCH_CONSTANT) / 2) - initial;
        // modifier = staticMod - (current / distance) * dynamicMod;
        modifier = 1.0;
        if(modifier > 1.0) modifier = 1.0;
            if (backwards) {
                backLeft.move(-speed * modifier);
                frontLeft.move(-speed * modifier);
                backRight.move(-speed * modifier);
                frontRight.move(-speed * modifier);    
            } else {
                backLeft.move(speed * modifier);
                frontLeft.move(speed * modifier);
                backRight.move(speed * modifier);
                frontRight.move(speed * modifier);
            }
        delay(20);
    }
    backLeft.move(0);
    frontLeft.move(0);
    backRight.move(0);
    frontRight.move(0);
}

void a_Turn(double angle,  double staticMod, double dynamicMod) {
    backLeft.tare_position();
    frontLeft.tare_position();
    backRight.tare_position();
    frontRight.tare_position();
    bool left = false;
    if (angle > 0.0) {
        left = true;
    }
    angle = fabs(angle);
    gyro.tare();
    int speed = 80;
    double modifier = 1.0;
    // if(angle < 0) speed *= -1;
    double current = 0.0;
    while(current < angle) {
        current = abs(gyro.get_rotation());
        // modifier = 2.0 - (current / angle) * 2.0;
        modifier = 1.0;
        if(modifier > 1.0) modifier = 1.0;
            if (left) {
                backLeft.move(speed * modifier);
                frontLeft.move(speed * modifier);
                backRight.move(-speed * modifier);
                frontRight.move(-speed * modifier);
            } else {
                backLeft.move(-speed * modifier);
                frontLeft.move(-speed * modifier);
                backRight.move(speed * modifier);
                frontRight.move(speed * modifier);
            }
        delay(20);
    }
    backLeft.move(0);
    frontLeft.move(0);
    backRight.move(0);
    frontRight.move(0);
}

void a_Intake(int speed) {
    intake.move(-speed * 127);
}

void a_FireCatapult() {
    catapultLeft.move(127);
    catapultRight.move(127);
    delay(500);
    catapultLeft.move(0);
    catapultRight.move(0);
}

void a_ReloadCatapult() {
    while (!catapultPrimeLeft.get_value() && !catapultPrimeRight.get_value()) {
        catapultLeft.move(127);
        catapultRight.move(127);
    }
    catapultLeft.brake();
    catapultRight.brake();
}