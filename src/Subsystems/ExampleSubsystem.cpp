#include "main.h"

//! Constructor
ExampleSubsystem::ExampleSubsystem() {
    // Motor Setup
    frontLeftMotor = new pros::Motor(frontLeftBasePort, baseMotorGearset, false, globalEncoderUnits);
	frontRightMotor = new pros::Motor(frontRightBasePort, baseMotorGearset, true, globalEncoderUnits);
	backLeftMotor = new pros::Motor(backLeftBasePort, baseMotorGearset, false, globalEncoderUnits);
	backRightMotor = new pros::Motor(backRightBasePort, baseMotorGearset, true, globalEncoderUnits);
    examplePiston = new pros::ADIDigitalOut(EXAMPLE_PISTON_PORT);
}

//Example Functions 
//AKA Functions for you to make Copy Pasta 

void ExampleSubsystem::move(int leftSpeed, int rightSpeed) {
    frontLeftMotor->move(leftSpeed);
	frontRightMotor->move(rightSpeed);
	backLeftMotor->move(leftSpeed);
	backRightMotor->move(rightSpeed);
}

/* Experimental Function (not yet tested) */
void ExampleSubsystem::moveForInches(int leftSpeed, int rightSpeed, double distance) { 
    //speeds should always be positive, use negative distance to move backwards

    double frontLeftInitialPos = frontLeftMotor->get_position();
    double frontRightInitialPos = frontRightMotor->get_position();
    double distanceInEncoderTicks = distance*rotationsPerInch*KTicksPerRotation;

    frontLeftMotor->move_relative(distanceInEncoderTicks, leftSpeed);
    frontRightMotor->move_relative(distanceInEncoderTicks, rightSpeed);
    backLeftMotor->move_relative(distanceInEncoderTicks, leftSpeed);
    backRightMotor->move_relative(distanceInEncoderTicks, rightSpeed);

    while (leftSpeed != 0 && !((frontLeftMotor->get_position() < (frontLeftInitialPos + distanceInEncoderTicks + 5)) && (frontLeftMotor->get_position() > (frontLeftInitialPos + distanceInEncoderTicks - 5)))) {
        pros::delay(2); // Continue running this loop as long as the motor is not within +-5 encoder units of its goal
    }
    while (rightSpeed != 0 && !((frontRightMotor->get_position() < (frontRightInitialPos + distanceInEncoderTicks + 5)) && (frontRightMotor->get_position() > (frontRightInitialPos + distanceInEncoderTicks - 5)))) {
        pros::delay(2); // Continue running this loop as long as the motor is not within +-5 encoder units of its goal
    }
}

/* Experimental Function (not yet tested) */
void ExampleSubsystem::turnForTicks(int leftSpeed, int rightSpeed, double turnTicks) {
    //speeds should always be positive, use negative turnTicks value to turn left, positive to turn right

    double frontLeftInitialPos = frontLeftMotor->get_position();
    double frontRightInitialPos = frontRightMotor->get_position();
    double leftTurnTicks = turnTicks;
    double rightTurnTicks = turnTicks * -1;

    frontLeftMotor->move_relative(leftTurnTicks, leftSpeed);
    frontRightMotor->move_relative(rightTurnTicks, rightSpeed);
    backLeftMotor->move_relative(leftTurnTicks, leftSpeed);
    backRightMotor->move_relative(rightTurnTicks, rightSpeed);

    while (leftSpeed != 0 && !((frontLeftMotor->get_position() < (frontLeftInitialPos + leftTurnTicks + 5)) && (frontLeftMotor->get_position() > (frontLeftInitialPos + leftTurnTicks - 5)))) {
        pros::delay(2); // Continue running this loop as long as the motor is not within +-5 encoder units of its goal
    }
    while (rightSpeed != 0 && !((frontRightMotor->get_position() < (frontRightInitialPos + rightTurnTicks + 5)) && (frontRightMotor->get_position() > (frontRightInitialPos + rightTurnTicks - 5)))) {
        pros::delay(2); // Continue running this loop as long as the motor is not within +-5 encoder units of its goal
    }
}

void ExampleSubsystem::tankDrive() { // Tank Drive function.
    static int tankLeftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    static int tankRightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    move(tankLeftSpeed, tankRightSpeed);
}

void ExampleSubsystem::arcadeDrive(bool split, bool reversed) { // Arcade Drive Function (includes Split, regular, and both sides for both). 
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

void ExampleSubsystem::zeroEncoders() {
	frontLeftMotor->set_zero_position(frontLeftMotor->get_position());
	frontRightMotor->set_zero_position(frontRightMotor->get_position());
	backLeftMotor->set_zero_position(backLeftMotor->get_position());
	backRightMotor->set_zero_position(backRightMotor->get_position());
}

void ExampleSubsystem::printEncoders() {
	printf("FrontLeft Position%f", frontLeftMotor->get_position());
	printf("FrontRight Position%f", frontRightMotor->get_position());
	printf("BackLeft Position%f", backLeftMotor->get_position());
	printf("BackRight Position%f", backRightMotor->get_position());
}

void ExampleSubsystem::pistonIn() {
    examplePiston->set_value(false);
}

void ExampleSubsystem::pistonOut() {
    examplePiston->set_value(true);
}