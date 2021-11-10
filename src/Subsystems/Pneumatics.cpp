#include "main.h"

//! Constructor
Pneumatics::Pneumatics() {
  FrontPiston = new pros::ADIDigitalOut(DIGITAL_PISTON_PORT_FRONT);
  BackPiston = new pros::ADIDigitalOut(DIGITAL_PISTON_PORT_BACK);
}

//! Functions
void Pneumatics::S_FrontPistonIn() {
    if (pneumaticsFrontPistonPos)
    {
    	FrontPiston->set_value(false);
        pneumaticsFrontPistonPos = false;
    }
}

void Pneumatics::S_BackPistonIn() {
    if (pneumaticsBackPistonPos)
    {
        BackPiston->set_value(false);
        pneumaticsBackPistonPos = false;
    }
}

void Pneumatics::S_FrontPistonOut() {
    if (!pneumaticsFrontPistonPos)
    {
        FrontPiston->set_value(true);
        pneumaticsFrontPistonPos = true;
    }
}

void Pneumatics::S_BackPistonOut() {
    if (!pneumaticsBackPistonPos)
    {
        BackPiston->set_value(true);
        pneumaticsBackPistonPos = true;
    }
}

void Pneumatics::pneumaticsTeleop() { // Tank Drive function.
    FrontPneumaticsOut = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    FrontPneumaticsIn = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    BackPneumaticsOut = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_X);
    BackPneumaticsIn = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_B);
    if(FrontPneumaticsOut)
    {
      S_FrontPistonOut();
    }
    if(FrontPneumaticsIn)
    {
      S_FrontPistonIn();
    }
    if(BackPneumaticsOut)
    {
      S_BackPistonOut();
    }
    if(BackPneumaticsIn)
    {
      S_BackPistonIn();
    }
}