#include "main.h"

//MOTORS
//Drivetrain
//Deperecated 2024-01-19
// extern Motor driveBLeft;
// extern Motor driveCLeft;
// extern Motor driveFLeft;
// extern Motor driveBRight;
// extern Motor driveCRight;
// extern Motor driveFRight;
// //Drivetrain Motor Groups
// extern Motor_Group drivetrainLeft;
// extern Motor_Group drivetrainRight;
extern std::shared_ptr<OdomChassisController> chassis;
extern std::shared_ptr<ChassisModel> chassisModel;

//Flywheel
extern pros::Motor fredwheel;

//Climb
extern pros::Motor climb;

//Pneumatics
extern pros::ADIDigitalOut pneumaticLeft;
extern pros::ADIDigitalOut pneumaticRight;

//Gyro
extern pros::IMU gyro;

//Controllers
extern pros::Controller master;
extern pros::Controller partner;