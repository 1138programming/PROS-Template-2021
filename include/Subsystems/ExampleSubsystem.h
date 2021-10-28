#include "main.h"

#ifndef EXAMPLESUBSYSTEM_H
#define EXAMPLESUBSYSTEM_H

class ExampleSubsystem {
    private:
        pros::Motor* leftExampleMotor;
        pros::Motor* rightExampleMotor;
    public:
        void move(int leftSpeed, int rightSpeed);
        void tankDrive();
        void arcade(bool split=true, bool reversed=false);
    ExampleSubsystem();
};

#endif