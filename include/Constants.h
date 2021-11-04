#include "main.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H
//! Motor ports
static const int leftBackMotorPort = 1;
static const int leftMiddleMotorPort = 1;
static const int leftFrontMotorPort = 2;
static const int rightBackMotorPort = 3;
static const int rightFrontMotorPort = 4;
static const int frontArmMotorPort = 8;
static const int backArmMotorPort = 9;
// const int otherMotorNamePort = 3;
// etc.

//! V5 Sensor Ports
const int imuPort = 20;
const int visionPort = 5;

//! ADI/Legacy Ports
static const std::uint8_t threeWireDevicePort = 'a';
// etc.

// V5 Motor gearsets
/*   Reference:
pros::E_MOTOR_GEARSET_36----------36:1, 100 RPM, Red gear set
pros::E_MOTOR_GEARSET_18----------18:1, 200 RPM, Green gear set
pros::E_MOTOR_GEARSET_06----------6:1, 600 RPM, Blue Gear Set
pros::E_MOTOR_GEARSET_INVALID-----Error return code
*/
static const pros::motor_gearset_e_t RedGearset = pros::E_MOTOR_GEARSET_36;
static const pros::motor_gearset_e_t GreenGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_gearset_e_t BlueGearset = pros::E_MOTOR_GEARSET_06;

// Global configurations
const pros::motor_encoder_units_e_t globalEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;
const pros::motor_brake_mode_e_t globalBrakeMode = pros::E_MOTOR_BRAKE_HOLD;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

// Encoder ports
const int exampleEncoderTopPort = 0;

// Global things that we need
const int imuPort = 20;
static const int maxAuton = 1;

#endif