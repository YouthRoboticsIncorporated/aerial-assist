#include "DriveForward.h"
#include "../Robotmap.h"

DriveForward::DriveForward():CommandBase("DriveForward"){
	Requires(chassis);
	SetTimeout(3.9);
}

void DriveForward::Initialize(){	
	
}

void DriveForward::Execute(){
	chassis->drive(1, 0, 0, 0.80);
    
}

bool DriveForward::IsFinished(){
    
    double AB = max(chassis->encoderA->Get(), chassis->encoderB->Get());
    
    double CD = max(chassis->encoderC->Get(), chassis->encoderD->Get());
    
    double Avg = max (AB, CD); 
    
	return IsTimedOut() || abs(Avg) > 2560;
}

void DriveForward::End(){
	chassis->drive (0,0,0,0);
}

void DriveForward::Interrupted(){
	End();
}	
