#include "main.h"

#ifndef BASE_H
#define BASE_H

class Base {
  private:
      // Base motors
      pros::Motor* frontLeftMotor;
      pros::Motor* frontRightMotor;
      pros::Motor* backLeftMotor;
      pros::Motor* backRightMotor;
  public:
      void move(int leftSpeed, int rightSpeed);
      /*void tankDrive();*/
  Base();
};

#endif