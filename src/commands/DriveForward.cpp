#include "DriveForward.h"
#include "../Robotmap.h"

DriveForward::DriveForward():CommandBase("DriveForward"){
	Requires(chassis);
	SetTimeout(3);
}

void DriveForward::Initialize(){	
	
}

void DriveForward::Execute(){
	chassis->drive(1, 0, 0, 0.40, true);
    
}

bool DriveForward::IsFinished(){
	return IsTimedOut() || beaglebone->goalRange != 99.0;
}

void DriveForward::End(){
	chassis->drive (0,0,0,0);
}

void DriveForward::Interrupted(){
	End();
}	
