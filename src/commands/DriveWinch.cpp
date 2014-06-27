#include "DriveWinch.h"
#include "WinchPayout.h"
#include "DriveForward.h" 

DriveWinch::DriveWinch(): CommandGroup("DriveWinch"){
	AddParallel(new WinchPayout());
    AddParallel(new DriveForward());
}
