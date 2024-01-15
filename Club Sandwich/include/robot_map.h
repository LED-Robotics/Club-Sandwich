#include "main.h"

using namespace pros;

//MOTORS
//Drivetrain
extern Motor driveBLeft;
extern Motor driveCLeft;
extern Motor driveFLeft;
extern Motor driveBRight;
extern Motor driveCRight;
extern Motor driveFRight;
//Drivetrain Motor Groups
extern Motor_Group drivetrainLeft;
extern Motor_Group drivetrainRight;

//Flywheel
extern Motor flywheel;

//Climb
extern Motor climb;

//Pneumatics
extern ADIDigitalOut pneumaticLeft;
extern ADIDigitalOut pneumaticRight;

//Gyro
extern ADIGyro gyro;

//Controllers
extern Controller master;
// extern Controller partner;