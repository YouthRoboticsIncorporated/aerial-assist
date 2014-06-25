#ifndef BallTrap_h
#define BallTrap_h

#include <WPILib.h>

class BallTrap : public Subsystem {
    public:
        BallTrap();
        ~BallTrap();
        void moveTrap(double speed);
    private:
        Victor* balltrapmotor;
};

#endif
