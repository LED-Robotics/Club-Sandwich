#include "controls.h"

const float driveDeadzone{.02};

int currentSignature{RED_ID}; //Default

int alliace{BLUE_ID}; //Default

int autonomousSelected{-1}; //Default

const controller_analog_e_t DRIVE_X{ANALOG_RIGHT_X};
const controller_analog_e_t DRIVE_Y{ANALOG_LEFT_Y};

bool partnerConnected{true};

bool catapultButtonOnly = false;

// const controller_id_e_t INTAKE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t CATAPULT_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t ELEVATE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};