#ifndef CONTROLS_H
#define CONTROLS_H
#include "robot_map.h"

#define RED_ID 1
#define BLUE_ID 2

extern const float driveDeadzone;

extern int currentSignature;

extern int alliance;

extern int autonomousSelected;

extern const controller_analog_e_t DRIVE_X;

extern const controller_analog_e_t DRIVE_Y;

extern bool partnerConnected;

//For separating commands between controllers
// extern const controller_id_e_t INTAKE_CONTROLLER;

// extern const controller_id_e_t CATAPULT_CONTROLLER;

// extern const controller_id_e_t ELEVATE_CONTROLLER;

#endif