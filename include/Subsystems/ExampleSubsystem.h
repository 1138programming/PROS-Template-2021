#include "main.h"

#ifndef EXAMPLESUBSYSTEM_H
#define EXAMPLESUBSYSTEM_H

class ExampleSubsystem {
    private:
        pros::Motor* frontLeftMotor;
        pros::Motor* frontRightMotor;
        pros::Motor* backLeftMotor;
        pros::Motor* backRightMotor;
        pros::ADIDigitalOut* examplePiston;

    public:
        // Basic move function example.
        void move(int speed);
        
        //Example Drive Functions for Teleop
        //AKA Functions for you to make Copy Pasta 
        void move(int leftSpeed, int rightSpeed);
        void moveForInches(int leftSpeed, int rightSpeed, double distance);
        void turnForTicks(int leftSpeed, int rightSpeed, double turnTicks);
        void tankDrive();
        void arcadeDrive(bool split=true, bool reversed=false);
        void zeroEncoders();
        void printEncoders();
        void pistonIn();
        void pistonOut();

    ExampleSubsystem();
};

#endif