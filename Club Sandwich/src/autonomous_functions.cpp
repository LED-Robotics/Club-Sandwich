#include "autonomous_functions.h"

const double INCH_CONSTANT = 0.0349065850398;

void autonDrive(double distance) {
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

void autonTurn(double angle) {
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

void autonIntake(bool forwards) {

}

void autonPrime() {
    while(catapultPrime.get_value()) {
        catapult.move(60);
    }
    catapult.move(10);
}

void autonCatapult() {
    autonPrime();
    catapult.move_relative(500, 500);
}