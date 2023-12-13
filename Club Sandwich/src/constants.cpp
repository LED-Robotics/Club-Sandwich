#include "constants.h"

//INITIALIZE
int currentSignature{RED_ID};

int alliance{BLUE_ID};

bool funButtonPressed = false;

int allianceSelected = 0;

bool pneumaticOut = false;


//AUTONOMOUS
const double INCH_CONSTANT = 0.0349065850398;

int autonomousSelected{-1};


//TELEOPERATED
//Driver
const float driveDeadzone{.02};

const controller_analog_e_t DRIVE_X{ANALOG_RIGHT_X};

const controller_analog_e_t DRIVE_Y{ANALOG_LEFT_Y};

double turnVar;

double straightVar;

bool bashMode = false;

//Catapult
bool automaticPrime = true;

bool loading = false;

//Controller
bool partnerConnected{true};

// const controller_id_e_t INTAKE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t CATAPULT_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t ELEVATE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};