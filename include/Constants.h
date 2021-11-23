#include "main.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

//! Motor ports
static const int rightArmMotorPort = 1;
static const int leftArmMotorPort = 2;
static const int intakeMotorPort = 3;
static const int clawMotorPort = 4;
static const int frontLeftBasePort = 5;
static const int frontRightBasePort = 6;
static const int backLeftBasePort = 7;
static const int backRightBasePort = 8;
// etc.

//! V5 Sensor Ports
const int imuPort = 20;

//! ADI/Legacy Ports
static const std::uint8_t EXAMPLE_THREE_WIRE_PORT = 'a';
static const std::uint8_t EXAMPLE_PISTON_PORT = 'e';
// etc.

//! Encoder ports
const int exampleEncoderTopPort = 0;


//! V5 Motor gearsets
/*   Reference:
pros::E_MOTOR_GEARSET_36----------36:1, 100 RPM, Red gear set
pros::E_MOTOR_GEARSET_18----------18:1, 200 RPM, Green gear set
pros::E_MOTOR_GEARSET_06----------6:1, 600 RPM, Blue Gear Set
pros::E_MOTOR_GEARSET_INVALID-----Error return code
*/
static const pros::motor_gearset_e_t KRedGearset = pros::E_MOTOR_GEARSET_36;
static const pros::motor_gearset_e_t KGreenGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_gearset_e_t KBlueGearset = pros::E_MOTOR_GEARSET_06;

//! Global configurations
const pros::motor_gearset_e_t  baseMotorGearset = KGreenGearset;
const pros::motor_gearset_e_t  intakeMotorGearset = KGreenGearset;
const pros::motor_gearset_e_t  clawMotorGearset = KGreenGearset;
const pros::motor_gearset_e_t  armMotorGearset = KGreenGearset;

const pros::motor_encoder_units_e_t globalEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;
const pros::motor_brake_mode_e_t globalBrakeMode = pros::E_MOTOR_BRAKE_HOLD;

//! Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int KTicksPerRotation = 360; // Encoder ticks in one revolution
const double rotationsPerInch = 1/4.5; //* For Base Only

//! Other Global things that we need
static const int maxAuton = 1;

#endif