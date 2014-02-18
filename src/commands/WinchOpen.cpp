#include "WinchOpen.h"
#include "WinchPayout.h"
#include "WinchRetract.h"
#include "QuickReleaseClose.h"
#include "QuickReleaseOpen.h"

WinchOpen::WinchOpen(): CommandGroup("WinchOpen"){
	AddSequential(new QuickReleaseOpen());
	AddSequential(new WinchPayout());
}
