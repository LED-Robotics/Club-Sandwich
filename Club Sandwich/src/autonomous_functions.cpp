#include "autonomous_functions.h"

void a_ChassisDrive(double distance, double staticMod, double dynamicMod) {
    driveBLeft.tare_position();
    driveFLeft.tare_position();
    driveBRight.tare_position();
    driveFRight.tare_position();
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
        initial = (abs(driveFLeft.get_position()) * INCH_CONSTANT + abs(driveFRight.get_position()) * INCH_CONSTANT) / 2 -12;
    } else {
        initial = (abs(driveFLeft.get_position()) * INCH_CONSTANT + abs(driveFRight.get_position()) * INCH_CONSTANT) / 2;
    }
    double current = 0.0;
    while(current < distance) {
        current = ((abs(driveFLeft.get_position()) * INCH_CONSTANT + abs(driveFRight.get_position()) * INCH_CONSTANT) / 2) - initial;
        // modifier = staticMod - (current / distance) * dynamicMod;
        modifier = 1.0;
        if(modifier > 1.0) modifier = 1.0;
            if (backwards) {
                driveBLeft.move(-speed * modifier);
                driveFLeft.move(-speed * modifier);
                driveBRight.move(-speed * modifier);
                driveFRight.move(-speed * modifier);    
            } else {
                driveBLeft.move(speed * modifier);
                driveFLeft.move(speed * modifier);
                driveBRight.move(speed * modifier);
                driveFRight.move(speed * modifier);
            }
        delay(20);
    }
    driveBLeft.move(0);
    driveFLeft.move(0);
    driveBRight.move(0);
    driveFRight.move(0);
}

void a_ChassisTurn(double angle,  double staticMod, double dynamicMod) {
    driveBLeft.tare_position();
    driveFLeft.tare_position();
    driveBRight.tare_position();
    driveFRight.tare_position();
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
                driveBLeft.move(speed * modifier);
                driveFLeft.move(speed * modifier);
                driveBRight.move(-speed * modifier);
                driveFRight.move(-speed * modifier);
            } else {
                driveBLeft.move(-speed * modifier);
                driveFLeft.move(-speed * modifier);
                driveBRight.move(speed * modifier);
                driveFRight.move(speed * modifier);
            }
        delay(20);
    }
    driveBLeft.move(0);
    driveFLeft.move(0);
    driveBRight.move(0);
    driveFRight.move(0);
}

void a_CatapultFire() {
    catapultLeft.move(127);
    catapultRight.move(127);
    delay(500);
    catapultLeft.move(0);
    catapultRight.move(0);
}

void a_CatapultReload() {
    while (!catapultPrimeLeft.get_value() && !catapultPrimeRight.get_value()) {
        catapultLeft.move(127);
        catapultRight.move(127);
    }
    catapultLeft.brake();
    catapultRight.brake();
}

void a_PneumaticFlexz(bool flex) {
    pneumaticLeft.set_value(flex);
    pneumaticRight.set_value(flex);
}