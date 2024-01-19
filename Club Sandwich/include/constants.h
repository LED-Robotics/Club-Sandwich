#ifndef CONTROLS_H
#define CONTROLS_H
#include "robot_map.h"

//INITIALIZE
#define RED_ID 1

#define BLUE_ID 2

extern int currentSignature;

extern bool funButtonPressed;

extern int alliance;

extern int allianceSelected;

extern bool pneumaticOut;

extern const double INCH_CONSTANT;


//AUTONOMOUS
#define LEFT 0

#define RIGHT 1

extern double gyroDegrees;

extern double angleDeadzone;

extern int autonomousSelected;


//TELEOPERATED
//Driver
extern const pros::controller_analog_e_t DRIVE_X;

extern const pros::controller_analog_e_t DRIVE_Y;

extern const float driveDeadzone;

extern const float driveCurveExtent;

extern bool bashMode;

//Catapult
extern bool automaticPrime;

extern bool loading;

//Controller
extern bool partnerConnected;

//For separating commands between controllers
// extern const controller_id_e_t INTAKE_CONTROLLER;

// extern const controller_id_e_t CATAPULT_CONTROLLER;

// extern const controller_id_e_t ELEVATE_CONTROLLER;

#endif