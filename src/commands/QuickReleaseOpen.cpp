#include "../subsystems/Catapult.h"
#include "../Robotmap.h"
#include "QuickReleaseOpen.h"

QuickReleaseOpen::QuickReleaseOpen():CommandBase("QuickReleaseOpen"){
	Requires(catapult);
	SetTimeout(QR_OPEN_TIMEOUT);
}

void QuickReleaseOpen::Initialize(){
	catapult-> qrStart();
}

void QuickReleaseOpen::Execute(){
}

bool QuickReleaseOpen::IsFinished(){
	return IsTimedOut()||catapult->qrPassingSwitchPressed();
}

void QuickReleaseOpen::End(){
	catapult->qrStop();
}

void QuickReleaseOpen::Interrupted(){
	End();
}	
