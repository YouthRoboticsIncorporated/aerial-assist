#include "FindPosition.h"
#include "../Robotmap.h"

#include <math.h>

FindPosition::FindPosition():CommandBase("FindPosition"){
	Requires(chassis);
	SetTimeout(6.0);
}

void FindPosition::Initialize(){	

}

void FindPosition::Execute(){
    double heading = beaglebone->goalAngle * 2.0 *3.14159/180.0;
    double range = beaglebone->goalRange;
    double speed = 1.0;
    
    if (range != 99.0) {
		
		if (range < MIN_FIRE_RANGE) {
			speed = -1.0;
		}
		
		double vX = speed*cos(heading); 
		double vY = speed*sin(heading);
		double vZ = heading/100.0;
		chassis->drive(vX,vY,vZ,0.75);
	}
}

bool FindPosition::IsFinished(){
	
	double range = beaglebone->goalRange;
	
	return IsTimedOut() || range == 99.0 ||
		(range > MIN_FIRE_RANGE && range < MAX_FIRE_RANGE);
}

void FindPosition::End(){
	chassis->drive (0,0,0,0);
}

void FindPosition::Interrupted(){
	End();
}	
