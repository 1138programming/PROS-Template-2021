#include "main.h"

#ifndef EXAMPLESUBSYSTEM_H
#define EXAMPLESUBSYSTEM_H

class ExampleSubsystem {
    private:
        pros::Motor* leftExampleMotor;
        pros::Motor* rightExampleMotor;
    public:
        // Basic move function example.
        void move(int speed);
        
        //Example Drive Functions for Teleop
        //AKA Functions for you to make Copy Pasta 
        void move(int leftSpeed, int rightSpeed);
        void tankDrive();
        void arcade(bool split=true, bool reversed=false);

    ExampleSubsystem();
};

#endif