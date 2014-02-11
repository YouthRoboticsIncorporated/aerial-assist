#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchRetract.h"

WinchRetract::WinchRetract():CommandBase("WinchRetract"){
	Requires(catapult);
	SetTimeout(WINCH_TIMEOUT);
}

void WinchRetract::Initialize(){
	catapult-> winchRetract();
}

void WinchRetract::Execute(){
}

bool WinchRetract::IsFinished(){
	return IsTimedOut()||catapult->cataLimitSwitchPressed();
}

void WinchRetract::End(){
	catapult->qrStop();
}

void WinchRetract::Interrupted(){
	End();
}	

