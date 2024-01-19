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
const pros::controller_analog_e_t DRIVE_X{ANALOG_RIGHT_X};

const pros::controller_analog_e_t DRIVE_Y{ANALOG_LEFT_Y};

const float driveDeadzone{.02};

const float driveCurveExtent{.95};

bool bashMode = false;

//Catapult
bool automaticPrime = true;

bool loading = false;

//Controller
bool partnerConnected{true};