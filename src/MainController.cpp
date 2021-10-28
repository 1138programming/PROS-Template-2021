#include "main.h"

MainController::MainController() {
    pros::Controller mainController (pros::E_CONTROLLER_MASTER);

    LeftY = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    RightY = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    LeftX = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    RightX = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    ButtonLeft = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
    ButtonRight = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
    ButtonUp = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    ButtonDown = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    ButtonA = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_A);
    ButtonB = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_B);
    ButtonX = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_X);
    ButtonY = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
    ButtonL1 = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    ButtonL2 = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    ButtonR1 = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    ButtonR2 = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
}