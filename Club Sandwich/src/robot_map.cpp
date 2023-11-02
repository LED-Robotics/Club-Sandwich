#include "robot_map.h"

Motor backLeft{12, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};
Motor frontLeft{11, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};
Motor backRight{2, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};
Motor frontRight{1, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};

Motor intake{15, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES};//*Small Motors 200 RPM

Motor catapult{16,MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};

ADIDigitalOut intakePiston{'G'};
ADIDigitalOut plowPiston{'H'};
ADIDigitalIn catapultPrime{'A'};
IMU gyro{20};

Controller master{CONTROLLER_MASTER};
Controller partner{CONTROLLER_PARTNER};