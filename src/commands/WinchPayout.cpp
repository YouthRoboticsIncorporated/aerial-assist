#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchPayout.h"

WinchPayout::WinchPayout():CommandBase("WinchPayout"){
	Requires(catapult);
}

void WinchPayout::Initialize(){
	catapult->winchCounter->Reset();
	catapult->winchCounter->Start();
	SetTimeout(WINCH_PAYOUT_TIMEOUT);
	catapult-> winchPayout();
}

void WinchPayout::Execute(){
}

bool WinchPayout::IsFinished(){
	return IsTimedOut() || catapult->winchCounter->Get()>WINCH_PAYOUT_COUNTS;
	// TODO - use line encoder on winch to detect correct number of rotations
}

void WinchPayout::End(){
	catapult->winchStop();
}

void WinchPayout::Interrupted(){
	End();
}	
