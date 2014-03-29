#ifndef ChopsticksDrop_h
#define ChopsticksDrop_h

#include "../CommandBase.h"

class ChopsticksDrop: public CommandBase{
	public:
		ChopsticksDrop();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
