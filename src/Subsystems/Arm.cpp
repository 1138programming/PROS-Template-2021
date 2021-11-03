#include "main.h"

//! Constructor
Arm::Arm() {
    // Motor Setup
    leftArmMotor = new pros::Motor(leftArmMotorPort, armMotorGearset, false, globalEncoderUnits);
    rightArmMotor = new pros::Motor(rightArmMotorPort, armMotorGearset, false, globalEncoderUnits);
}

//! Functions
void Arm::move(int speed) {
  if (bumper1->get_value() || bumper2->get_value()) {
    leftArmMotor->move(0);
    rightArmMotor->move(0);
    if (speed > 0) {
      leftArmMotor->move(speed);
      rightArmMotor->move(speed);
    } else if (speed < 0) {
      leftArmMotor=0;
      rightArmMotor=0;
    }

  } else {
    leftArmMotor->move(speed);
    rightArmMotor->move(speed);
  }
}


void Arm::armTeleop() { // Tank Drive function.
    if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      move(KMaxMotorSpeed);
    }
    else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      move(-KMaxMotorSpeed);
    }
    else {
      move(0);
    }
}