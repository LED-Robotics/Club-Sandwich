#include "constants.h"

//INITIALIZE
int currentSignature{RED_ID};

int alliance{BLUE_ID};

bool funButtonPressed = false;

int allianceSelected = 0;

bool pneumaticOut = false;

const double INCH_CONSTANT = 0.0349065850398; //Pineapples


//AUTONOMOUS
double gyroDegrees = 0.0;

double angleDeadzone = 2.0;

int autonomousSelected{-1};


//TELEOPERATED
//Driver
const float driveDeadzone{.02};

bool bashMode = false;

//Catapult
bool automaticPrime = true;

bool loading = false;

//Controller
bool partnerConnected{true};

// const controller_id_e_t INTAKE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t CATAPULT_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t ELEVATE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};