#include "main.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H
//! Motor ports
static const int leftExampleMotorPort = 1;
static const int rightExampleMotorPort = 2;
// const int otherMotorNamePort = 3;
// etc.

//! V5 Sensor Ports
const int imuPort = 20;

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

//! ADI/Legacy Ports
static const std::uint8_t threeWireDevicePort = 'a';
// const std::uint8_t otherThreeWireDevicePort = 'b';
// etc.

//! Global configurations
const pros::motor_encoder_units_e_t globalEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;
const pros::motor_brake_mode_e_t globalBrakeMode = pros::E_MOTOR_BRAKE_HOLD;

//! Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int KTicksPerRotation = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; //* For Base Only / TODO check if this is correct

//! Encoder ports
const int exampleEncoderTopPort = 0;

//! Global things that we need

#endif