#ifndef QuickReleaseOpen_h
#define QuickReleaseOpen_h

#include "../CommandBase.h"

class QuickReleaseOpen:public CommandBase{
	public:
		QuickReleaseOpen();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
