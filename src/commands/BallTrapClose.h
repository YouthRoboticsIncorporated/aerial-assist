#ifndef BallTrapClose_h
#define BallTrapClose_h

#include "../CommandBase.h"

class BallTrapClose: public CommandBase{
    public:
        BallTrapClose();
        virtual void Initialize();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void End();
        virtual void Interrupted();
};

#endif
