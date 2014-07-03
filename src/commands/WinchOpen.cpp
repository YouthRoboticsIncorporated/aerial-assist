#include "WinchOpen.h"
#include "WinchPayout.h"
#include "WinchRetract.h"


WinchOpen::WinchOpen(): CommandGroup("WinchOpen"){
	AddSequential(new WinchPayout());
}
