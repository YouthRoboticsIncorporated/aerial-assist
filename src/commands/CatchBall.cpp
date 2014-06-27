#include "CatchBall.h"
#include "../subsystems/Chassis.h"
#include "../Robotmap.h"




CatchBall::CatchBall(): CommandBase("CatchBall"){
	Requires(chassis);
}

void CatchBall::Initialize(){
}

void CatchBall::Execute(){
	if (beaglebone->isConnected && beaglebone->ballX <= 1.0 
		&& beaglebone->ballX >= -1.0) {
		double throttle = -0.67 * beaglebone->ballDiam * 1.33; 
		chassis->drive(-beaglebone->ballY, -beaglebone->ballX, 0.0, throttle);
	} else {
		double x = oi->getJoyDrvX();
		double y = oi->getJoyDrvY();
		double z = oi->getJoyDrvZ();
		double throttle = oi->getJoyDrvThrottle();
   
		chassis->drive(x, y, z, throttle);
	}
}

bool CatchBall::IsFinished(){
	return false; 
}

void CatchBall::End(){
	
}

void CatchBall::Interrupted(){
	End();
	
}


