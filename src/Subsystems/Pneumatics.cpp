#include "main.h"

//! Constructor
Pneumatics::Pneumatics() {
  FrontPiston = new pros::ADIDigitalOut(DIGITAL_PISTON_PORT_FRONT);
}

//! Functions
void Pneumatics::S_FrontPistonIn() {
    if (pneumaticsFrontPistonPos)
    {
    	FrontPiston->set_value(false);
        pneumaticsFrontPistonPos = false;
    }
}

void Pneumatics::S_FrontPistonOut() {
    if (!pneumaticsFrontPistonPos)
    {
        FrontPiston->set_value(true);
        pneumaticsFrontPistonPos = true;
    }
}

void Pneumatics::pneumaticsTeleop() { // Tank Drive function.
    FrontPneumaticsOut = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    FrontPneumaticsIn = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    if(FrontPneumaticsOut)
    {
      S_FrontPistonOut();
    }
    if(FrontPneumaticsIn)
    {
      S_FrontPistonIn();
    }
}