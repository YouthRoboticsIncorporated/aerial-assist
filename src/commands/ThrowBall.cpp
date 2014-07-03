#include "ThrowBall.h"
#include "WinchPayout.h"
#include "WinchRetract.h"
#include "QuickReleaseClose.h"
#include "QuickReleaseOpen.h"

ThrowBall::ThrowBall(): CommandGroup("ThrowBall"){
	AddSequential(new QuickReleaseOpen());
	AddSequential(new QuickReleaseClose());
	AddSequential(new WinchRetract());
    AddSequential(new WinchPayout());
}
