#include "main.h"

#ifndef PNEUMATICS_H
#define PNEUMATICS_H

class Pneumatics {
  private:
    pros::ADIDigitalOut* FrontPiston;
    bool FrontPneumaticsOut;
    bool FrontPneumaticsIn;
    bool pneumaticsFrontPistonPos;
  public:
    void pneumaticsTeleop();
    void S_FrontPistonOut();
    void S_FrontPistonIn();
    Pneumatics();
};

#endif