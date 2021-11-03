#include "main.h"

Intake::Intake() {
  // Get intake motors
  intakeMotor = new pros::Motor(intakeMotorPort, intakeMotorGearset, false, globalEncoderUnits);
  intakeMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Intake::move(int speed) {
  intakeMotor->move(speed);
  //printf("Motor speed set to %d\n", speed);
}

void Intake::intakeTeleop() { // Tank Drive function.
    static bool stoppable = true;
    if(mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
    {
      move(KMaxMotorSpeed);
    }
    else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      move(-KMaxMotorSpeed);
    }
    else {
      if (stoppable) {
        move(0);
      }
    }
    if(mainController.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      stoppable = false;
      move(KMaxMotorSpeed);
    }
    else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      stoppable = true;
      move(0);
    }
}