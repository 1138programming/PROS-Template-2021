#include "main.h"
#include "MainController.h"
#include "Constants.h"

//! Constructor
Base::Base() {
    // Motor Setup
    leftBackMotor = new pros::Motor(leftBackMotorPort, KGreenGearset, false, globalEncoderUnits);
    leftFrontMotor = new pros::Motor(leftBackMotorPort, KGreenGearset, false, globalEncoderUnits);
    rightBackMotor = new pros::Motor(rightBackMotorPort, KGreenGearset, true, globalEncoderUnits);
    rightFrontMotor = new pros::Motor(rightBackMotorPort, KGreenGearset, true, globalEncoderUnits);
}

//! Functions
void Base::move(int leftSpeed, int rightSpeed) { // Regular move functions.
    leftBackMotor->move(leftSpeed);
    leftFrontMotor->move(leftSpeed);
    rightBackMotor->move(rightSpeed);
    rightFrontMotor->move(rightSpeed);
}

void Base::tankDrive() { // Tank Drive function.
    static int tankLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    static int tankRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    move(tankLeftSpeed, tankRightSpeed);
}

void Base::arcade(bool split, bool reversed) { // Arcade Drive Function (includes Split, regular, and both sides for both). 
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