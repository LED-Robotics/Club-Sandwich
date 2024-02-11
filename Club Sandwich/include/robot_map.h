#include "main.h"

using namespace okapi;

extern std::shared_ptr<OdomChassisController> chassis;
extern std::shared_ptr<ChassisModel> chassisModel;

//Motors

extern Motor intake;

extern Motor flyWheel;

extern Motor backLeft;
extern Motor frontLeft;
extern Motor backRight;
extern Motor frontRight;


// //Digital Out/In
extern pros::ADIDigitalOut intakePiston;

extern pros::ADIDigitalOut backFlaps;

extern pros::IMU gyro;

extern pros::Controller master;
extern pros::Controller partner;