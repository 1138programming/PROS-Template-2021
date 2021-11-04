#include main.h;

AutonChooser::AutonChooser() {
    autonNumber = 1;
}

AutonChooser::autonChooserInit() {
    if (autonNumber != maxAuton) {
        autonNumber++;
    }
    else {
        autonNumber = 1;
    }
    switch(autonNumber) {
        case 1:
            master.set_text(mainController, 0, 0, "Auton 1");
            break;
    }
}

AutonChooser::autonChooserRun() {
    switch(autonNumber) {
        case 1:
            autonOne();
            break;
    }
}

// put actual auton here
AutonChooser::autonOne() {
    
}