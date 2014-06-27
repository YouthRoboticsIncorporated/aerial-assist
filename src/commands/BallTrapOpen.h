#ifndef BallTrapOpen_h
#define BallTrapOpen_h

#include "../CommandBase.h"

class BallTrapOpen: public CommandBase{
    public:
        BallTrapOpen();
        virtual void Initialize();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void End();
        virtual void Interrupted();
};

#endif
