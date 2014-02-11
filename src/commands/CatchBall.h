#ifndef CATCH_BALL_H
#define CATCH_BALL_H

#include "../CommandBase.h"
#include <WPILib.h>


class CatchBall: public CommandBase{
    public:
        CatchBall();
        virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
		
	private:
};

#endif



