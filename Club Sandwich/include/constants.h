#ifndef CONTROLS_H
#define CONTROLS_H
#include "robot_map.h"

//DEFAULT
#define RED_ID 1

#define BLUE_ID 2

extern int currentSignature;

extern int alliance;


//AUTONOMOUS
extern int autonomousSelected;


//TELEOPERATED
//Driver
extern const float driveDeadzone;

extern const controller_analog_e_t DRIVE_X;

extern const controller_analog_e_t DRIVE_Y;

extern double turnVar;

extern double straightVar;

extern double bashMode;

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