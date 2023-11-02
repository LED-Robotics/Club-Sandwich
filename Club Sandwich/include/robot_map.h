#include "main.h"

using namespace pros;

//Motors
extern Motor backLeft;
extern Motor frontLeft;
extern Motor backRight;
extern Motor frontRight;

extern Motor Intake;

extern Motor catapult;

// //Digital Out/In
extern ADIDigitalOut intakePiston;
extern ADIDigitalOut plowPiston;

extern ADIDigitalIn limitSwitch;
extern ADIDigitalIn catapultPrime;
extern IMU gyro;

extern Controller master;
extern Controller partner;