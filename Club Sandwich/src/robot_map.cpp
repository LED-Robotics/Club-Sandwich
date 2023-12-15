#include "robot_map.h"

std::shared_ptr<OdomChassisController> chassis =
ChassisControllerBuilder()
.withMotors(
    {-2, -4, -18}, // Left motors are 1 & 2 (reversed)
    {1, 17, 3}    // Right motors are 3 & 4
)
// Green gearset, 4 in wheel diam, 11.5 in wheel track
.withDimensions({AbstractMotor::gearset::blue, (5.0 / 3.0)}, {{3.25_in, 19.0_in}, imev5BlueTPR})
.withGains(
    {0.001, 0.0, 0.0000},
    {0.001, 0.0, 0.0000},
    {0.000, 0.0, 0.0000}
)
.withOdometry()
.buildOdometry();
std::shared_ptr<ChassisModel> chassisModel = chassis->getModel();

Motor backLeft{4, true, AbstractMotor::gearset::blue , AbstractMotor::encoderUnits::degrees};
Motor frontLeft{2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};
Motor backRight{3, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};
Motor frontRight{1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};

Motor intake{11, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};//*Small Motors 200 RPM

Motor catapult{10,true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees};
Motor catapult2{6, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees};
Motor leftPlow {15, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};
Motor rightPlow{16, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};

pros::ADIDigitalOut intakePiston{'H'};

pros::ADIAnalogIn catapultLineSense{'G'};
pros::IMU gyro{20};

pros::Controller master{CONTROLLER_MASTER};
pros::Controller partner{CONTROLLER_PARTNER};

