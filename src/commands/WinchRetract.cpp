#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "WinchRetract.h"

WinchRetract::WinchRetract(bool UseLimitSwitch):CommandBase("WinchRetract"){
	Requires(catapult);
	UseLimitSwitch_ = UseLimitSwitch;
}

void WinchRetract::Initialize(){
	SetTimeout(WINCH_RETRACT_TIMEOUT);
	catapult-> winchRetract();
}

void WinchRetract::Execute(){
}

bool WinchRetract::IsFinished(){
	return IsTimedOut() || (catapult->cataLimitSwitchPressed() && UseLimitSwitch_);
}

void WinchRetract::End(){
	catapult->winchStop();
}

void WinchRetract::Interrupted(){
	End();
}	

