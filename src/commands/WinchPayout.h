#ifndef WinchPayout_h
#define WinchPayout_h

#include "../CommandBase.h"

class WinchPayout:public CommandBase{
	public:
		WinchPayout();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
