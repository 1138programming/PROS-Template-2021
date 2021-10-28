#include "main.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
// Motor ports
static const int MOTOR_NAME_PORT = 1;
// const int OTHER_MOTOR_NAME_PORT = 2;
// etc.

// 3-
static const std::uint8_t THREE_WIRE_DEVICE_PORT = 'a';
// const std::uint8_t OTHER_THREE_WIRE_DEVICE_PORT = 'b';
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

#endif