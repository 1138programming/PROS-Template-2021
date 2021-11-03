#include "main.h"

//! Constructor
Arm::Arm() {
    // Motor Setup
    frontArm = new pros::Motor(frontArmMotorPort, KRedGearset, false, globalEncoderUnits);
    backArm = new pros::Motor(backArmMotorPort, KRedGearset, false, globalEncoderUnits);
}

//! Functions
void Arm::moveFrontArm(int armSpeed) { // Arm move function.
    frontArm->move(armSpeed);
}
void Arm::moveBackArm(int armSpeed) { // Arm move function.
    backArm->move(armSpeed);
}
