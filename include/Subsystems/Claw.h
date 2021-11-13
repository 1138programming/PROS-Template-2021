#include "main.h"

#ifndef CLAW_H
#define CLAW_H

class Claw {
  private:
    pros::Motor* clawMotor;

  public:
    void move(int speed);
    void clawTeleop();
    Claw();
};

#endif