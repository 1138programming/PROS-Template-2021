#include "main.h"

std::uint32_t startTime = 0;
bool fiveSeconds = false;

//! Constructor
Base::Base() {
  // Motor Setup
	frontLeftMotor = new pros::Motor(frontLeftBasePort, baseMotorGearset, false, globalEncoderUnits);
	frontRightMotor = new pros::Motor(frontRightBasePort, baseMotorGearset, true, globalEncoderUnits);
	backLeftMotor = new pros::Motor(backLeftBasePort, baseMotorGearset, false, globalEncoderUnits);
	backRightMotor = new pros::Motor(backRightBasePort, baseMotorGearset, true, globalEncoderUnits);
	


	startTime = pros::millis();
	fiveSeconds = false;
}

//! Functions

void Base::move(int leftSpeed, int rightSpeed) {
	frontLeftMotor->move(leftSpeed);
	frontRightMotor->move(rightSpeed);
	backLeftMotor->move(leftSpeed);
	backRightMotor->move(rightSpeed);
}

/*
void Base::tankDrive() { // Tank Drive function.
  static int leftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  static int rightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  move(leftSpeed, rightSpeed);
}*/
