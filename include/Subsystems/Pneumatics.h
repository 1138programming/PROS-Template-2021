#include "main.h"

#ifndef PNEUMATICS_H
#define PNEUMATICS_H

class Pneumatics {
  private:
    pros::ADIDigitalOut* FrontPiston;
    pros::ADIDigitalOut* BackPiston;
    bool FrontPneumaticsOut;
    bool FrontPneumaticsIn;
    bool BackPneumaticsOut;
    bool BackPneumaticsIn;
    bool pneumaticsFrontPistonPos;
    bool pneumaticsBackPistonPos;
  public:
    void pneumaticsTeleop();
    void S_FrontPistonOut();
    void S_FrontPistonIn();
    void S_BackPistonOut();
    void S_BackPistonIn();
    Pneumatics();
};

#endif