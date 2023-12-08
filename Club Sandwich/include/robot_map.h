#include "main.h"

using namespace okapi;

extern std::shared_ptr<ChassisController> chassis;

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
extern pros::ADIDigitalOut intakePiston;
extern pros::ADIAnalogIn catapultLineSense;
extern pros::ADIDigitalIn limitSwitch;
extern pros::ADIDigitalIn catapultPrime;
extern pros::IMU gyro;

extern pros::Controller master;
extern pros::Controller partner;