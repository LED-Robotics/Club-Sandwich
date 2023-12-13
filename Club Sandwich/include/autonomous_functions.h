#include "robot_map.h"
#include "constants.h"

void a_ChassisDrive(double distance, double staticMod, double dynamicMod);

void a_ChassisTurn(double angle, double staticMod, double dynamicMod);

void a_CatapultFire();

void a_CatapultReload();

void a_PneumaticFlexz(bool flex);