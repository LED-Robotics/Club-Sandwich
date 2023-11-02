#include "robot_map.h"

//MOTORS
//Driver
Motor backLeft{4, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};
Motor frontLeft{2, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};
Motor backRight{3, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};
Motor frontRight{1, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};

//Intake
Motor intake{6, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};//*Small Motors 200 RPM

//Catapult
Motor catapultLeft{20, MOTOR_GEAR_RED, false, MOTOR_ENCODER_DEGREES};
Motor catapultRight{7, MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES};

//Elevator
Motor hook{5, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES};

//Limit Switch
ADIDigitalIn catapultPrime{'A'};

//Gyro
IMU gyro{9};

//Controller
Controller master{CONTROLLER_MASTER};
// Controller partner{CONTROLLER_PARTNER};