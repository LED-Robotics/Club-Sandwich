#include "main.h"

using namespace okapi;

extern std::shared_ptr<OdomChassisController> chassis;
extern std::shared_ptr<ChassisModel> chassisModel;

//Motors
extern Motor backLeft;
extern Motor frontLeft;
extern Motor backRight;
extern Motor frontRight;

extern Motor intake;

extern Motor thunker;
extern Motor catapult2;

extern Motor leftPlow;
extern Motor rightPlow;

// //Digital Out/In
extern pros::ADIDigitalOut intakePiston;
extern pros::ADIAnalogIn thunkerLineSense;
extern pros::ADIDigitalIn limitSwitch;
extern pros::ADIDigitalIn catapultPrime;
extern pros::IMU gyro;

extern pros::Controller master;
extern pros::Controller partner;