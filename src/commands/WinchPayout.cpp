#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchPayout.h"

WinchPayout::WinchPayout():CommandBase("WinchPayout"){
	Requires(catapult);
	SetTimeout(WINCH_TIMEOUT);
}

void WinchPayout::Initialize(){
	catapult-> winchPayout();
}

void WinchPayout::Execute(){
}

bool WinchPayout::IsFinished(){
	return IsTimedOut() || false;
	// TODO - use line encoder on winch to detect correct number of rotations
}

void WinchPayout::End(){
	catapult->qrStop();
}

void WinchPayout::Interrupted(){
	End();
}	
