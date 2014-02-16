#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchPayout.h"

WinchPayout::WinchPayout():CommandBase("WinchPayout"){
	Requires(catapult);
}

void WinchPayout::Initialize(){
	SetTimeout(WINCH_PAYOUT_TIMEOUT);
	catapult-> winchPayout();
}

void WinchPayout::Execute(){
}

bool WinchPayout::IsFinished(){
	return IsTimedOut(); //|| false;
	// TODO - use line encoder on winch to detect correct number of rotations
}

void WinchPayout::End(){
	catapult->winchStop();
}

void WinchPayout::Interrupted(){
	End();
}	
