#include "main.h"

#ifndef ARM_H
#define ARM_H

class Arm {
    private:
    pros::Motor* leftArmMotor;
    pros::Motor* rightArmMotor;
    pros::ADIDigitalIn* bumper1;
    pros::ADIDigitalIn* bumper2;
  public:
    static const double kLowTowerPos;
    static const double kMidTowerPos;

    void move(int speed);
    void armTeleop();
    Arm();
};

#endif