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

void Base::moveFor(int leftSpeed, int rightSpeed, double distance) {
	frontLeftMotor->move_relative(distance*KTicksPerRotation*rotationsPerInch, leftSpeed);
	frontRightMotor->move_relative(distance*KTicksPerRotation*rotationsPerInch, rightSpeed);
	backLeftMotor->move_relative(distance*KTicksPerRotation*rotationsPerInch, leftSpeed);
	backRightMotor->move_relative(distance*KTicksPerRotation*rotationsPerInch, rightSpeed);
}

void Base::zeroEncoders() {
	frontLeftMotor->set_zero_position(frontLeftMotor->get_position());
	frontRightMotor->set_zero_position(frontRightMotor->get_position());
	backLeftMotor->set_zero_position(backLeftMotor->get_position());
	backRightMotor->set_zero_position(backRightMotor->get_position());
}

void Base::printEncoders() {
	printf("FrontLeft Position %ffrontLeftMotor->get_position());
	printf("FrontRight Position" + frontRightMotor->get_position());
	printf("BackLeft Position" + backLeftMotor->get_position());
	printf("BackRight Position" + backRightMotor->get_position());
}

/*
void Base::tankDrive() { // Tank Drive function.
  static int leftSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  static int rightSpeed = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  move(leftSpeed, rightSpeed);
}*/
