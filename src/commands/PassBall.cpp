#include "PassBall.h"
#include "WinchPayout.h"
#include "WinchRetract.h"
#include "QuickReleaseClose.h"
#include "QuickReleaseOpen.h"


PassBall::PassBall(){
    AddSequential(new WinchRetract());
    AddSequential(new QuickReleaseOpen());
	AddSequential(new WinchPayout());
	AddSequential(new QuickReleaseClose());
    AddSequential(new WinchRetract());
    AddSequential(new WinchPayout());

}
