#include "main.h"

using namespace pros;

//MOTORS
//Driver
extern Motor driveBLeft;
extern Motor driveFLeft;
extern Motor driveBRight;
extern Motor driveFRight;

//Catapult
extern Motor catapultLeft;
extern Motor catapultRight;

//Elevator
// extern Motor hook;

//Limit Switch
extern ADIDigitalIn catapultPrimeLeft;
extern ADIDigitalIn catapultPrimeRight;

//Pneumatics
extern ADIDigitalOut pneumaticLeft;
extern ADIDigitalOut pneumaticRight;

//Gyro
extern IMU gyro;

//Controllers
extern Controller master;
// extern Controller partner;