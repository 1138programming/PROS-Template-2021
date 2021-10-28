#include "main.h"
#include "MainController.h"
#include "Constants.h"

pros::Motor MotorName(MOTOR_NAME_PORT, GreenGearset, false, globalEncoderUnits);

void ExampleSubsystemMove(int speed) {
    MotorName = speed;
}

void ExampleSubsystemTeleop() {
    int motorSpeed = MainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    ExampleSubsystemMove(motorSpeed);
}