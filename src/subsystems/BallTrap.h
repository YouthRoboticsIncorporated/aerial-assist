#ifndef BallTrap_h
#define BallTrap_h

#include <WPILib.h>

class BallTrap : public Subsystem {
    public:
        BallTrap();
        ~BallTrap();
        void moveRightTrap(double speed);
        void moveLeftTrap(double speed);
    private:
        Victor* leftballtrapmotor;
        Victor* rightballtrapmotor;
};

#endif
