#include "FindPosition.h"
#include "../Robotmap.h"

FindPosition::FindPosition():CommandBase("FindPosition"){
	Requires(chassis);
	SetTimeout(6.0);
}

void FindPosition::Initialize(){	

}

void FindPosition::Execute(){
    double angle = beaglebone->goalAngle * 2.0 *3.14159/180.0;
    double range = beaglebone->goalRange;
    double speed = 1.0;
    
    if (range < MIN_FIRE_RANGE) {
		speed = -1.0;
	}
    
    double vX = speed*Cos(heading); 
    double vY = speed*Sin(heading);
    double vZ = heading/100.0;
    chassis->drive(vX,vY,vZ,1.0,false);
}

bool FindPosition::IsFinished(){
	return IsTimedOut() ||
		(beaglebone->goalRange > MIN_FIRE_RANGE && beaglebone->goalRange < MAX_FIRE_RANGE);
}

void FindPosition::End(){
	chassis->drive (0,0,0,0);
}

void FindPosition::Interrupted(){
	End();
}	
