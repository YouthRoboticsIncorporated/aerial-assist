#ifndef ChopsticksStop_h
#define ChopsticksStop_h

#include "../CommandBase.h"

class ChopsticksStop: public CommandBase{
	public:
		ChopsticksStop();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
