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
	return IsTimedOut() || catapult->qrFiringSwitchPressed();
}

void QuickReleaseClose::End(){
	catapult->qrStop();
}

void QuickReleaseClose::Interrupted(){
	End();
}	
