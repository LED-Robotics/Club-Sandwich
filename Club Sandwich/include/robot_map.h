#include "main.h"

using namespace pros;

//Motors
extern Motor backLeft;
extern Motor frontLeft;
extern Motor backRight;
extern Motor frontRight;

extern Motor intake;

extern Motor catapult;
extern Motor catapult2;

extern Motor leftPlow;
extern Motor rightPlow;

// //Digital Out/In
extern ADIDigitalOut intakePiston;
extern ADIAnalogIn catapultLineSense;
extern ADIDigitalIn limitSwitch;
extern ADIDigitalIn catapultPrime;
extern IMU gyro;

extern Controller master;
extern Controller partner;