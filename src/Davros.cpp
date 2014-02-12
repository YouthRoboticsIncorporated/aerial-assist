#include "CommandBase.h"

#include "Davros.h"
#include "Robotmap.h"


Davros::Davros()
{

}

void Davros::RobotInit() {
    CommandBase::init();
    autonomousCommand = NULL;
    lw = LiveWindow::GetInstance();    
}

void Davros::AutonomousInit() {
    //autonomousCommand->Start();
    
}

void Davros::AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
}

void Davros::TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to 
    // continue until interrupted by another command, remove
    // this line or comment it out.
    //autonomousCommand->Cancel();
    

}

void Davros::TeleopPeriodic() {
    Scheduler::GetInstance()->Run();
    smartDashboard(); // Update SDB values
    
}

void Davros::TestInit() {
}

void Davros::TestPeriodic() {
    lw->Run();
}

void Davros::smartDashboard() {
	// Update the Smart Dashboard values
	// Call from TeleopPeriodic and AutonomousPeriodic
    SmartDashboard::PutData(Scheduler::GetInstance());
    
    SmartDashboard::PutData(CommandBase::chassis);
	SmartDashboard::PutData(CommandBase::chopsticks);
	SmartDashboard::PutData(CommandBase::catapult);
	
	SmartDashboard::PutBoolean("QR Fire Limit",
		CommandBase::catapult->qrFiringSwitchPressed());
	SmartDashboard::PutBoolean("QR Pass Limit",
		CommandBase::catapult->qrPassingSwitchPressed());
	SmartDashboard::PutBoolean("Catapult Arm Limit",
		CommandBase::catapult->cataLimitSwitchPressed());
}	


START_ROBOT_CLASS(Davros);

