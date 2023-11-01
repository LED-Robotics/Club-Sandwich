#include "robot_map.h"

Motor backLeft{4, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};
Motor frontLeft{2, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES};
Motor backRight{3, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};
Motor frontRight{1, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_DEGREES};

Motor Intake{11, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES};//*Small Motors 200 RPM

Motor catapult{7,MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES};

ADIDigitalOut intakePiston{'G'};
ADIDigitalIn limitSwitch{'H'};
ADIDigitalIn catapultPrime{'A'};
IMU gyro{20};

Controller master{CONTROLLER_MASTER};
Controller partner{CONTROLLER_PARTNER};

