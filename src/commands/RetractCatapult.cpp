#include "RetractCatapult.h"
#include "WinchRetract.h"
#include "QuickReleaseClose.h"


RetractCatapult::RetractCatapult(){
	AddSequential(new QuickReleaseClose());
	AddSequential(new WinchRetract());
}
