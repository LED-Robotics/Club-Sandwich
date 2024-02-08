#include "autonomous_functions.h"

#include "robot_map.h"

// const double INCH_CONSTANT = 0.09794150344116636047315923899847;
// const double INCH_CONSTANT = 58.76490206469981;
const double INCH_CONSTANT = 34.617869579932255;  // guess this bozo

// void autonDrive(double distance) {
//     backLeft.tare_position();
//     backRight.tare_position();
//     frontLeft.tare_position();
//     frontRight.tare_position();
//     int speed = 100;
//     double modifier = 1.0;
//     distance *= INCH_CONSTANT;
//     if(distance < 0) speed *= -1;
//     double initial = (abs(frontLeft.get_position()) + abs(frontRight.get_position())) / 2;
//     double current = 0.0;
//     pros::lcd::print(2, "Initial: %f", initial);
//     pros::lcd::print(3, "Distance: %f", distance);
//     distance = abs(distance);
//     while(current < distance) {
//         current = ((abs(frontLeft.get_position()) + abs(frontRight.get_position())) / 2) - initial;
//         pros::lcd::print(4, "current: %f", current);
//         if(current / distance > 0.85 && frontLeft.get_actual_velocity() < 4.0) break;
//         modifier = 1.8 - (current / distance) * 1.8;
//         if(modifier > 1.0) modifier = 1.0;

//         backLeft.move(speed * modifier);
//         frontLeft.move(speed * modifier);
//         backRight.move(speed * modifier);
//         frontRight.move(speed * modifier);
//         delay(20);
//     }
//     backLeft.move(0);
//     frontLeft.move(0);
//     backRight.move(0);
//     frontRight.move(0);
// }

// void autonTurn(double angle) {
//     gyro.tare();
//     int speed = 80;
//     double modifier = 1.0;
//     if(angle < 0) speed *= -1;
//     double current = 0.0;
//     angle = abs(angle);
//     while(current < angle) {
//         current = abs(gyro.get_rotation());
//         modifier = 1.8 - (current / angle) * 1.5;
//         if(modifier > 1.0) modifier = 1.0;

//         backLeft.move(speed * modifier);
//         frontLeft.move(speed * modifier);
//         backRight.move(-speed * modifier);
//         frontRight.move(-speed * modifier);
//         delay(20);
//     }
//     backLeft.move(0);
//     frontLeft.move(0);
//     backRight.move(0);
//     frontRight.move(0);
// }

// void autonIntake(bool forwards) {

// }

// void autonPrime() {
//     while(catapultLineSense.get_value() > 1200) {
//         catapult.move(100);
//         catapult2.move(100);
//     }
//     catapult.move(15);
//     catapult2.move(15);
// }

// void autonCatapult() {
//     autonPrime();
//     catapult.move_relative(500, 500);
// }
void autonTare(){
    chassis->stop();
    chassis->setState({0_ft, 0_ft, 0_deg});
    chassis->waitUntilSettled();

}

// void goofyAsyncs(QLength daDistnace){//distance looper cause turning is god
//     chassis->moveDistanceAsync(daDistnace);
//     pros::delay(500);
//     while (!chassis->isSettled()){
//         //While pid says isnt settled, if velocity comes to a near stop, break the async and continue
//         double avgRPM=(fabs(backLeft.getActualVelocity())+fabs(frontLeft.getActualVelocity())+fabs(backRight.getActualVelocity())+fabs(frontRight.getActualVelocity()))/4;
//         if(avgRPM < 3.0){//If robot velocity is less than 10 RPM and distance traveled is over half 
//             chassis->stop();
//             break;
//         }
//     }
// }

void useLEDS(uint32_t LED_LEFT_COLOR, uint32_t LED_RIGHT_COLOR) {
    leftLED.set_all(LED_LEFT_COLOR);
    rightLED.set_all(LED_RIGHT_COLOR);
}