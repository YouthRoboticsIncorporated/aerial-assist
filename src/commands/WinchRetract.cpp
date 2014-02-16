#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchRetract.h"

WinchRetract::WinchRetract():CommandBase("WinchRetract"){
	Requires(catapult);
}

void WinchRetract::Initialize(){
	SetTimeout(WINCH_RETRACT_TIMEOUT);
	catapult-> winchRetract();
}

void WinchRetract::Execute(){
}

bool WinchRetract::IsFinished(){
	return IsTimedOut() || catapult->cataLimitSwitchPressed();
}

void WinchRetract::End(){
	catapult->winchStop();
}

void WinchRetract::Interrupted(){
	End();
}	

