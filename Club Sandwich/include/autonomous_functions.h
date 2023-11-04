#include "robot_map.h"
#include "constants.h"

void a_Drive(double distance, double staticMod, double dynamicMod);

void a_Turn(double angle, double staticMod, double dynamicMod);

void a_Intake(int speed);

void a_FireCatapult();

void a_ReloadCatapult();