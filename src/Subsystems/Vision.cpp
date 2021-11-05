#include "main.h"

//! Constructor
Vision::Vision() {
    pros::Vision visionSensor(visionPort);
}

void Vision::setSigs() {
	pros::vision_signature_s_t firstSig =
		pros::Vision::signature_from_utility(1, 553, 1245, 899, -4843, -4291, -4567, 3.500, 0);
	pros::vision_signature_s_t secondSig =
		pros::Vision::signature_from_utility(2, 7997, 9993, 8995, -3135, -1857, -2496, 3.000, 0);

	visionSensor->set_signature(1, &firstSig);
	visionSensor->set_signature(2, &secondSig);
}

void Vision::locateObject(pros::vision_signature_s_t sig) {
	
}
//! Functions
/*pros::vision_signature_s_t firstSig =
		pros::Vision::signature_from_utility(1, 553, 1245, 899, -4843, -4291, -4567, 3.500, 0);
	pros::vision_signature_s_t secondSig =
		pros::Vision::signature_from_utility(2, 7997, 9993, 8995, -3135, -1857, -2496, 3.000, 0);

	see.set_signature(1, &firstSig);
	see.set_signature(2, &secondSig);
	
	while (true) {
		pros::vision_object_s_t sig1 = see.get_by_sig(0, 1);
		pros::vision_object_s_t sig2 = see.get_by_sig(0, 2);
		
		std::cout << sig1.signature << "			" << sig2.signature << "\n";

		//vision_object_s_t rtn = vision_sensor.get_by_size(0);

		//pros::vision_object_s_t sigthing = see.get_by_size(0);
    	// Gets the largest object
    	//std::cout << "\n" << sigthing.signature;
    	//delay(2);
	
	}*/
//}