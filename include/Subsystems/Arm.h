#include "main.h"

#ifndef ARM_H
#define ARM_H

class Arm {
    private:
        pros::Motor* frontArm;
        pros::Motor* backArm;
    public:
        void moveFrontArm(int armSpeed);
        void moveBackArm(int armSpeed);
    Arm();
};

#endif