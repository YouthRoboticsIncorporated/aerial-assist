#include "AutonomousCommandGroup.h"
#include "QuickReleaseClose.h"
#include "QuickReleaseOpen.h"
#include "FindPosition.h"
#include "ChopsticksDrop.h"
#include "DriveWinch.h"
#include "WinchRetract.h"
#include "WinchPayout.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential (new DriveWinch());
	AddSequential (new ChopsticksDrop());
	//AddSequential (new FindPosition());
	AddSequential(new QuickReleaseOpen());
	AddSequential(new QuickReleaseClose());
	AddSequential(new WinchRetract());
    AddSequential(new WinchPayout());
}
