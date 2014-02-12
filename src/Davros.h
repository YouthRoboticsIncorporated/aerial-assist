#ifndef Davros_h
#define Davros_h

#include "WPILib.h"

class Davros : public IterativeRobot {
    private:
        Command *autonomousCommand;
        LiveWindow *lw;
        void smartDashboard();
        
    public:
		Davros();
        void RobotInit();
        void AutonomousInit();
        void AutonomousPeriodic();
        void TeleopInit();
        void TeleopPeriodic();
        void TestInit();
        void TestPeriodic();
};

#endif
