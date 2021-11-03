#include "main.h"

#ifndef INTAKE_H
#define INTAKE_H

class Intake {
  private:
    pros::Motor* intakeMotor;

  public:
    void move(int speed);
    void intakeTeleop();
    Intake();
};

#endif