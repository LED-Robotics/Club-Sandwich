#include "robot_map.h"

//MOTORS
//Driver
Motor driveBLeft{1, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};
Motor driveCLeft{2, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};
Motor driveFLeft{3, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};
Motor driveBRight{11, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};
Motor driveCRight{12, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};
Motor driveFRight{13, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};

//Flywheel
Motor flywheelGoBurr{15, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};

//Pneumatics
ADIDigitalOut pneumaticLeft{'A'};
ADIDigitalOut pneumaticRight{'H'};

//Gyro
IMU gyro{14};

//Controller
Controller master{CONTROLLER_MASTER};
// Controller partner{CONTROLLER_PARTNER};