#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "QuickReleaseClose.h"

QuickReleaseClose::QuickReleaseClose():CommandBase("QuickReleaseClose") {
	Requires(catapult);
}

void QuickReleaseClose::Initialize(){
	SetTimeout(QR_CLOSE_TIMEOUT);
	catapult-> qrStart();
}

void QuickReleaseClose::Execute(){
}

bool QuickReleaseClose::IsFinished(){
	return TimeSinceInitialized() > QR_CLOSE_MIN_TIME && 
		(IsTimedOut() || catapult->qrFiringSwitchPressed()) 
		&& !catapult->qrPassingSwitchPressed();
}

void QuickReleaseClose::End(){
	catapult->qrStop();
}

void QuickReleaseClose::Interrupted(){
	End();
}	
