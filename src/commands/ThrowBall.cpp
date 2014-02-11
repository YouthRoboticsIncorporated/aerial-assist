#include "ThrowBall.h"
#include "WinchPayout.h"
#include "WinchRetract.h"
#include "QuickReleaseClose.h"
#include "QuickReleaseOpen.h"

ThrowBall::ThrowBall(){
	AddSequential(new WinchPayout());
	AddSequential(new QuickReleaseOpen());
	AddSequential(new QuickReleaseClose());
	AddSequential(new WinchRetract());
}
