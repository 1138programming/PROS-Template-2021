#include "main.h"

//! Constructor
ExampleSubsystem::ExampleSubsystem() {
    // Motor Setup
    leftExampleMotor = new pros::Motor(leftExampleMotorPort, KGreenGearset, false, globalEncoderUnits);
    rightExampleMotor = new pros::Motor(rightExampleMotorPort, KGreenGearset, true, globalEncoderUnits);
}

//! Functions
void ExampleSubsystem::move(int speed) { // Basic move function example.
    leftExampleMotor->move(speed);
    rightExampleMotor->move(speed);
}


//Example Drive Functions for Teleop
//AKA Functions for you to make Copy Pasta 

void ExampleSubsystem::move(int leftSpeed, int rightSpeed) {
    leftExampleMotor->move(leftSpeed);
    rightExampleMotor->move(rightSpeed);
    //etc.
}

void ExampleSubsystem::tankDrive() { // Tank Drive function.
    static int tankLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    static int tankRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    move(tankLeftSpeed, tankRightSpeed);
}

void ExampleSubsystem::arcade(bool split, bool reversed) { // Arcade Drive Function (includes Split, regular, and both sides for both). 
    static int arcadeLeftSpeed;
    static int arcadeRightSpeed;
    if (split) { // If split-arcade is true ...
        if (!reversed) { // If vertical is not set to be on the left side ...
            arcadeLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            arcadeRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            // ... set the speeds to reflect that.
        }
        else { // Otherwise ...
            arcadeLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) + mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
            arcadeRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) - mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
            // ... set the speeds to reflect that.
        }
    }
    else { // Else (regular arcade) ...
        if (!reversed) { // If vertical is not set to be on the left side ...
            arcadeLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
            arcadeRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
            // ... set the speeds to reflect that.
        }
        else { // Otherwise ...
            arcadeLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) + mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            arcadeRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) - mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            // ... set the speeds to reflect that.
        }
    }
    move(arcadeLeftSpeed, arcadeRightSpeed); // Move at the set speeds.
}