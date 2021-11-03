#include "main.h"

#ifndef BASE_H
#define BASE_H

class Base {
    private:
        pros::Motor* leftBackMotor;
        pros::Motor* leftFrontMotor;
        pros::Motor* rightBackMotor;
        pros::Motor* rightFrontMotor;
    public:
        void move(int leftSpeed, int rightSpeed);
        void tankDrive();
        void arcade(bool split=true, bool reversed=false);
    Base();
};

#endif