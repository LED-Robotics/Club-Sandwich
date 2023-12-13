#include "robot_map.h"

//MOTORS
//Driver
Motor driveBLeft{4, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};
Motor driveFLeft{2, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};
Motor driveBRight{3, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};
Motor driveFRight{1, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};

//Catapult
Motor catapultLeft{20, MOTOR_GEAR_RED, false, MOTOR_ENCODER_DEGREES};
Motor catapultRight{7, MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES};

//Elevator
// Motor hook{5, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES};

//Limit Switch
ADIDigitalIn catapultPrimeLeft{'A'};
ADIDigitalIn catapultPrimeRight{'B'};

//Pneumatics
ADIDigitalOut pneumaticLeft{'C'};
ADIDigitalOut pneumaticRight{'D'};

//Gyro
IMU gyro{9};

//Controller
Controller master{CONTROLLER_MASTER};
// Controller partner{CONTROLLER_PARTNER};