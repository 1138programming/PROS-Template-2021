#include "main.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H
//! Motor ports
static const int rightArmMotorPort = 15;
static const int leftArmMotorPort = 18;
static const int intakeMotorPort = 19;
static const int clawMotorPort = 6;
static const int frontLeftBasePort = 9;
static const int frontRightBasePort = 16;
static const int backLeftBasePort = 3;
static const int backRightBasePort = 10;

static const std::uint8_t threeWireDevicePort = 'a';

static const std::uint8_t DIGITAL_PISTON_PORT_FRONT = 'e';
// const int otherMotorNamePort = 3;
// etc.

//! V5 Sensor Ports
const int imuPort = 20;

//! ADI/Legacy Ports

//! V5 Motor gearsets
/*   Reference:
pros::E_MOTOR_GEARSET_36----------36:1, 100 RPM, Red gear set
pros::E_MOTOR_GEARSET_18----------18:1, 200 RPM, Green gear set
pros::E_MOTOR_GEARSET_06----------6:1, 600 RPM, Blue Gear Set
pros::E_MOTOR_GEARSET_INVALID-----Error return code
*/
const double kLowTowerPos = 2500;
const double kMidTowerPos = 3000;

static const pros::motor_gearset_e_t  baseMotorGearset = pros::E_MOTOR_GEARSET_18;
static const pros::motor_gearset_e_t  intakeMotorGearset = pros::E_MOTOR_GEARSET_18;
static const pros::motor_gearset_e_t  clawMotorGearset = pros::E_MOTOR_GEARSET_18;
static const pros::motor_gearset_e_t  armMotorGearset = pros::E_MOTOR_GEARSET_06;

//! ADI/Legacy Port
// const std::uint8_t otherThreeWireDevicePort = 'b';
// etc.

//! Global configurations
const pros::motor_encoder_units_e_t globalEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;
const pros::motor_brake_mode_e_t globalBrakeMode = pros::E_MOTOR_BRAKE_HOLD;

//! Motor and encoder constants
const int KTicksPerRotation = 360; // Encoder ticks in one revolution
const double rotationsPerInch = 1/4.5; //* For Base Only

//! Encoder ports

//! Global things that we need
static const int KMaxMotorSpeed = 127;
static const int maxAuton = 1;
#endif