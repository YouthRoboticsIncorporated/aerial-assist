#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchPayout.h"

WinchPayout::WinchPayout():CommandBase("WinchPayout", WINCH_TIMEOUT){
	Requires(catapult);
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
