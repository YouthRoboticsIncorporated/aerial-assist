#ifndef WinchRetract_h
#define WinchRetract_h

#include "../CommandBase.h"

class WinchRetract:public CommandBase{
	public:
		WinchRetract();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
