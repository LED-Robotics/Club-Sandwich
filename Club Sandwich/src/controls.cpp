#include "controls.h"

const float driveDeadzone{.02};
const float driveCurveExtent{0.95};

int currentSignature{RED_ID};

int alliance{BLUE_ID};

int autonomousSelected{0};

const controller_analog_e_t DRIVE_X{ANALOG_RIGHT_X};
const controller_analog_e_t DRIVE_Y{ANALOG_LEFT_Y};

bool partnerConnected{true};

// const controller_id_e_t INTAKE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t CATAPULT_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};

// const controller_id_e_t ELEVATE_CONTROLLER{CONTROLLER_MASTER / CONTROLLER_PARTNER};