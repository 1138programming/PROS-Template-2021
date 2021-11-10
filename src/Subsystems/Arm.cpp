#include "main.h"

//! Constructor
Arm::Arm() {
    // Motor Setup
    leftArmMotor = new pros::Motor(leftArmMotorPort, armMotorGearset, false, globalEncoderUnits);
    rightArmMotor = new pros::Motor(rightArmMotorPort, armMotorGearset, true, globalEncoderUnits);
    leftArmMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    rightArmMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

//! Functions
void Arm::move(int speed) {
  leftArmMotor->move(speed);
  rightArmMotor->move(speed);
}


void Arm::armTeleop() { // Tank Drive function.
    if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      move(KMaxMotorSpeed*0.5);
    }
    else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      move(-KMaxMotorSpeed*0.5);
    }
    else {
      move(0);
    }
}