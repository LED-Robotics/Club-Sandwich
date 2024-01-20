#include "robot_map.h"

//MOTORS
//Drivetrain
//Deprecated 2024-01-19
// Motor driveBLeft{1, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES}; //1
// Motor driveCLeft{2, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES}; //2
// Motor driveFLeft{3, MOTOR_GEAR_BLUE, false, MOTOR_ENCODER_DEGREES}; //3
// Motor driveBRight{11, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //11
// Motor driveCRight{12, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //12
// Motor driveFRight{13, MOTOR_GEAR_BLUE, true, MOTOR_ENCODER_DEGREES}; //13
// //Drivetrain Motor Groups
// Motor_Group drivetrainLeft({driveBLeft, driveCLeft, driveFLeft});
// Motor_Group drivetrainRight({driveBRight, driveCRight, driveFRight});

std::shared_ptr<OdomChassisController> chassis =
ChassisControllerBuilder()
.withMotors(
    {1, 2, 3}, // Left motors are 1 & 2 (reversed)
    {-11, -12, -13}    // Right motors are 3 & 4
)
// Green gearset, 4 in wheel diam, 11.5 in wheel track
.withDimensions({AbstractMotor::gearset::blue, (1.0)}, {{4.25_in, 14.0_in}, imev5BlueTPR})//BUTTER ACTUAL BOT:{AbstractMotor::gearset::blue, (X.0 / Y.0)}, {{4.25_in, 5.0_in}, imev5BlueTPR}
.withGains(
    {0.00090, 0.0, 0.0000},
    {0.00090, 0.0, 0.0000},
    {0.000, 0.0, 0.0000}
)
.withOdometry()
.buildOdometry();
std::shared_ptr<ChassisModel> chassisModel = chassis->getModel();

//Flywheel
pros::Motor fredwheel{15, MOTOR_GEAR_GREEN, true, MOTOR_ENCODER_DEGREES}; //15

//Climb
pros::Motor climb{5, MOTOR_GEAR_RED, true, MOTOR_ENCODER_DEGREES}; //5

//Pneumatics
pros::ADIDigitalOut pneumaticLeft{'H'}; //H
pros::ADIDigitalOut pneumaticRight{'A'}; //A

//Gyro
pros::IMU gyro{14}; //14

//Controller
pros::Controller master{CONTROLLER_MASTER};
pros::Controller partner{CONTROLLER_PARTNER};