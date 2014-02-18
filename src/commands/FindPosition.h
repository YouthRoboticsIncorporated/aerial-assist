#ifndef FindPosition_h
#define FindPosition_h

#include "../CommandBase.h"

class FindPosition: public CommandBase{
	public:
		FindPosition();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
