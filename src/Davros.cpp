#include "CommandBase.h"

#include "Davros.h"
#include "Robotmap.h"
#include "commands/AutonomousCommandGroup.h"


Davros::Davros()
{

}

void Davros::RobotInit() {
    CommandBase::init();
    autonomousCommand = new AutonomousCommandGroup();
    lw = LiveWindow::GetInstance();    
}

void Davros::AutonomousInit() {
    autonomousCommand->Start();
    
}

void Davros::AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
}

void Davros::TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to 
    // continue until interrupted by another command, remove
    // this line or comment it out.
	autonomousCommand->Cancel();
    

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
	SmartDashboard::PutData(CommandBase::forklift);
	
	SmartDashboard::PutBoolean("QR Fire Limit",
		CommandBase::catapult->qrFiringSwitchPressed());
	SmartDashboard::PutBoolean("QR Pass Limit",
		CommandBase::catapult->qrPassingSwitchPressed());
	SmartDashboard::PutBoolean("Catapult Arm Limit",
		CommandBase::catapult->cataLimitSwitchPressed());
	SmartDashboard::PutNumber("Ball Range", 
		CommandBase::beaglebone->ballRange());
#ifndef IR_DEBUG
	SmartDashboard::PutNumber("Winch Counter",
		CommandBase::catapult->winchCounter->Get());
	SmartDashboard::PutBoolean("Winch Trigger",
		CommandBase::catapult->lineCounterTrigger->GetTriggerState());
#else
	SmartDashboard::PutNumber("IR Voltage", 
		CommandBase::catapult->irSensor->GetAverageVoltage());
#endif
}	


START_ROBOT_CLASS(Davros);

