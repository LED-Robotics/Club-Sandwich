#include "robot_map.h"
#include "controls.h"

#define LEFT 0
#define RIGHT 1
extern const double INCH_CONSTANT;

void autonDrive(double distance);

void autonTurn(double angle);

void autonIntake(bool forwards);

void autonPrime();

void autonCatapult();

void autonTare();