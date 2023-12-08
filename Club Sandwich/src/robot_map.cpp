#include "robot_map.h"

std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
.withMotors(
    {-4, -2}, // Left motors are 1 & 2 (reversed)
    {3, 1}    // Right motors are 3 & 4
)
// Green gearset, 4 in wheel diam, 11.5 in wheel track
.withDimensions(AbstractMotor::gearset::blue, {{4_in, 11.5_in}, imev5BlueTPR})
.build();

Motor backLeft{4, true, AbstractMotor::gearset::blue , AbstractMotor::encoderUnits::degrees};
Motor frontLeft{2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};
Motor backRight{3, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};
Motor frontRight{1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};

Motor intake{11, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};//*Small Motors 200 RPM

Motor catapult{7,true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees};
Motor catapult2{6, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees};
Motor leftPlow {15, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};
Motor rightPlow{16, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};

pros::ADIDigitalOut intakePiston{'G'};

pros::ADIAnalogIn catapultLineSense{'H'};
pros::IMU gyro{20};

pros::Controller master{CONTROLLER_MASTER};
pros::Controller partner{CONTROLLER_PARTNER};

