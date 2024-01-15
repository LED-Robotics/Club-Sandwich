#include "robot_map.h"

//MOTORS
//Drivetrain
Motor driveBLeft{1, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES}; //1
Motor driveCLeft{2, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES}; //2
Motor driveFLeft{3, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES}; //3
Motor driveBRight{11, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //11
Motor driveCRight{12, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //12
Motor driveFRight{13, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //13
//Drivetrain Motor Groups
Motor_Group drivetrainLeft({driveBLeft, driveCLeft, driveFLeft});
Motor_Group drivetrainRight({driveBRight, driveCRight, driveCRight});

//Flywheel
Motor flywheel{15, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //15

//Climb
Motor climb{5, MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES}; //5

//Pneumatics
ADIDigitalOut pneumaticLeft{'A'}; //A
ADIDigitalOut pneumaticRight{'H'}; //H

//Gyro
ADIGyro gyro{14}; //14

//Controller
Controller master{CONTROLLER_MASTER};
// Controller partner{CONTROLLER_PARTNER};