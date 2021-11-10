#include "main.h"

AutonChooser::AutonChooser() {
    autonNumber = 0;
}

void AutonChooser::autonChooserInit() {
    if (autonNumber != maxAuton) {
        autonNumber++;
    }
    else {
        autonNumber = 1;
    }
    switch(autonNumber) {
        case 1:
            mainController.set_text(0, 0, "Auton 1");
            break;
    }
}

void AutonChooser::autonChooserRun() {
    switch(autonNumber) {
        case 1:
            autonOne();
            break;
    }
}

// put actual auton here
void AutonChooser::autonOne() {
    pneumatics->S_FrontPistonOut();
    base->moveFor(60, 60, 61.0);
}