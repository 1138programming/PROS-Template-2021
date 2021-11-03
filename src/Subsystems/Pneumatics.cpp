#include "main.h"

//! Constructor
Pneumatics::Pneumatics() {
  FrontPiston = new pros::ADIDigitalOut(DIGITAL_PISTON_PORT_FRONT);
  BackPiston = new pros::ADIDigitalOut(DIGITAL_PISTON_PORT_BACK);
}

//! Functions
void Pneumatics::S_FrontPistonIn() {
    if (Pneumatics::pneumaticsFrontPistonPos)
    {
        FrontPiston->set_value(false);
        pneumaticsFrontPistonPos = false;
    }
    
}

void Pneumatics::S_BackPistonIn() {
    if (Pneumatics::pneumaticsBackPistonPos)
    {
        BackPiston->set_value(false);
        pneumaticsBackPistonPos = false;
    }
}

void Pneumatics::S_FrontPistonOut() {
    if (!Pneumatics::pneumaticsFrontPistonPos)
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
    static bool FrontPneumaticsOut = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    static bool FrontPneumaticsIn = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    static bool BackPneumaticsOut = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_X);
    static bool BackPneumaticsIn = mainController.get_digital(pros::E_CONTROLLER_DIGITAL_B);
    if(FrontPneumaticsOut == true)
    {
      S_FrontPistonOut();
    }
    if(FrontPneumaticsIn == true)
    {
      S_FrontPistonIn();
    }
    if(BackPneumaticsOut == true)
    {
      S_BackPistonOut();
    }
    if(BackPneumaticsIn == true)
    {
      S_BackPistonIn();
    }
}