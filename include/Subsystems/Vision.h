#include "main.h"

#ifndef VISION_H
#define VISION_H

class Vision {
    private:
        pros::Vision* visionSensor;
    public:
        void setSigs();
        void locateObject(pros::vision_signature_s_t sig);
    Vision();
};

#endif