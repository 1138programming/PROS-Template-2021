#include "main.h"

Claw::Claw() {
  // Get claw motors
  clawMotor = new pros::Motor(clawMotorPort, clawMotorGearset, false, globalEncoderUnits);
  clawMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Claw::move(int speed) {
  clawMotor->move(speed);
  //printf("Motor speed set to %d\n", speed);
}

void Claw::clawTeleop() { // Tank Drive function.
    static bool stoppable = true;
    if(mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
    {
      move(KMaxMotorSpeed);
    }
    else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
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