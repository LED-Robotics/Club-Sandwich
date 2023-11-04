#include "robot_map.h"

Motor backLeft{4, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};
Motor frontLeft{2, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES};
Motor backRight{3, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};
Motor frontRight{1, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES};

Motor intake{11, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES};//*Small Motors 200 RPM

Motor catapult{7,MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES};
Motor catapult2{6,MOTOR_GEAR_RED, false, MOTOR_ENCODER_DEGREES};
Motor leftPlow {15, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES};
Motor rightPlow{16, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES};

ADIDigitalOut intakePiston{'G'};

ADIAnalogIn catapultLineSense{'H'};
IMU gyro{20};

Controller master{CONTROLLER_MASTER};
Controller partner{CONTROLLER_PARTNER};

