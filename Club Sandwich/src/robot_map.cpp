#include "robot_map.h"
#include "controls.h"

std::shared_ptr<OdomChassisController> chassis =
ChassisControllerBuilder()
.withMotors(
    {-2, -4, -18}, // Left motors are 1 & 2 (reversed)
    {1, 17, 3}    // Right motors are 3 & 4
)
// Green gearset, 4 in wheel diam, 11.5 in wheel track
.withDimensions({AbstractMotor::gearset::blue, (5.0/3.0)}, {{3.25_in, 16.9_in}, imev5BlueTPR})//KALEB ACTUAL BOT:{AbstractMotor::gearset::blue, (5.0 / 3.0)}, {{3.25_in, 19.0_in}, imev5BlueTPR}
.withGains(
    {0.00115, 0.0, 0.0000},
    {0.00115, 0.0, 0.0000},
    {0.000, 0.0, 0.0000}
)
.withOdometry()
.buildOdometry();
std::shared_ptr<ChassisModel> chassisModel = chassis->getModel();

Motor intake{9, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees};//*Small Motors 200 RPM

Motor flyWheel{14,false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees};

Motor leftFlap{5, true, AbstractMotor::gearset::invalid, AbstractMotor::encoderUnits::degrees};

pros::ADIDigitalOut intakePiston{'H'};

pros::ADIDigitalOut backFlaps{'G'};

pros::IMU gyro{20};

pros::Controller master{CONTROLLER_MASTER};
pros::Controller partner{CONTROLLER_PARTNER};

pros::ADILED leftLED{'A', leftLEDLength};
pros::ADILED rightLED{'B', rightLEDLength};