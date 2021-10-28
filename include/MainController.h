#include "main.h"

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

class MainController {
    public:
        static pros::Controller mainController;
        std::int32_t LeftY;
        std::int32_t RightY;
        std::int32_t LeftX;
        std::int32_t RightX;

        std::int32_t ButtonLeft;
        std::int32_t ButtonRight;
        std::int32_t ButtonUp;
        std::int32_t ButtonDown;
        std::int32_t ButtonA;
        std::int32_t ButtonB;
        std::int32_t ButtonX;
        std::int32_t ButtonY;
        std::int32_t ButtonL1;
        std::int32_t ButtonL2;
        std::int32_t ButtonR1;
        std::int32_t ButtonR2;
    MainController();
};

#endif