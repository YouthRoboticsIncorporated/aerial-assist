#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "QuickReleaseOpen.h"

QuickReleaseOpen::QuickReleaseOpen():CommandBase("QuickReleaseOpen"){
	Requires(catapult);
}

void QuickReleaseOpen::Initialize(){
	SetTimeout(QR_OPEN_TIMEOUT);
	catapult-> qrStart();
}

void QuickReleaseOpen::Execute(){
}

bool QuickReleaseOpen::IsFinished(){
	return IsTimedOut() || catapult->qrPassingSwitchPressed();
}

void QuickReleaseOpen::End(){
	catapult->qrStop();
}

void QuickReleaseOpen::Interrupted(){
	End();
}	
