#include "OI.h"
#include "Robotmap.h"
#include "commands/CatchBall.h"
#include "commands/ChopsticksStop.h"
#include "commands/ThrowBall.h"
#include "commands/PassBall.h"
#include "commands/ChopsticksMoveUp.h"
#include "commands/ChopsticksMoveDown.h"
#include "commands/RetractCatapult.h"
#include "commands/WinchPayout.h"
#include "commands/WinchRetract.h"
#include "commands/WinchOpen.h"
#include "commands/QuickReleaseClose.h"


OI::OI() {
	// Process operator interface input here.
	joyDrv = new Joystick(1);
	
	catchButton = new JoystickButton(joyDrv,CATCH_BUTTON);
	catchButton->WhileHeld(new CatchBall());
	
	throwButton = new JoystickButton(joyDrv,THROW_BUTTON);
	throwButton->WhenPressed(new ThrowBall());
	
	passButton = new JoystickButton(joyDrv,PASS_BUTTON);
	passButton->WhenPressed(new PassBall());
	
	chopsticksStopButton = new JoystickButton(joyDrv,CHOPSTICKS_STOP_BUTTON);
	chopsticksStopButton->WhenPressed(new ChopsticksStop());
	
	chopsticksMoveUpButton = new JoystickButton(joyDrv,CHOPSTICKS_MOVE_UP_BUTTON);
	chopsticksMoveUpButton->WhileHeld(new ChopsticksMoveUp());
	chopsticksMoveDownButton = new JoystickButton(joyDrv, CHOPSTICKS_MOVE_DOWN_BUTTON);
	chopsticksMoveDownButton->WhileHeld(new ChopsticksMoveDown());
	
	retractButton = new JoystickButton(joyDrv, RETRACT_BUTTON);
	retractButton->WhileHeld(new WinchRetract());
	payoutButton = new JoystickButton(joyDrv, PAYOUT_BUTTON);
	payoutButton->WhileHeld(new WinchPayout());
	
	winchOpenButton = new JoystickButton(joyDrv, WINCH_OPEN_BUTTON);
	winchOpenButton->WhileHeld(new WinchOpen());
	
	qrCloseButton = new JoystickButton(joyDrv, QR_CLOSE_BUTTON);
	qrCloseButton->WhileHeld(new QuickReleaseClose());

}

Joystick* OI::getJoyDrv() {
	return joyDrv;
}

double OI :: applyDeadZone(double input, double deadZone){
	if(input <= - deadZone || input >= deadZone){
		return input;
	}
	return 0.0;
}

double OI::getJoyDrvX(){
	return -applyDeadZone(joyDrv->GetY(), JOY_DRV_DEAD_X);
}

double OI::getJoyDrvY(){
	return -applyDeadZone(joyDrv->GetX(), JOY_DRV_DEAD_Y);
}

double OI::getJoyDrvZ(){
	return -applyDeadZone(joyDrv->GetZ(), JOY_DRV_DEAD_Z);
}

double OI::getJoyDrvThrottle(){
	return -(joyDrv->GetTwist()-1.0)/2.0;
}

bool OI::weBePimpin(){
	return joyDrv->GetRawButton(PIMP_ROLL_BUTTON);
}
