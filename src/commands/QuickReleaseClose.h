#ifndef QuickReleaseClose_h
#define QuickReleaseClose_h

#include "../CommandBase.h"

class QuickReleaseClose:public CommandBase{
	public:
		QuickReleaseClose();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
