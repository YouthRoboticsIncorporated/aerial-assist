#include "Catapult.h"
#include "../Robotmap.h"

Catapult::Catapult():Subsystem("Catapult"){
	releaseMotor = new Victor (RELEASE_MOTOR_PWM);
	winchMotor = new Victor (WINCH_MOTOR_PWM);
	qrFiringLimitSwitch = new DigitalInput (QR_FIRING_LIMIT_SWITCH);
	qrPassingLimitSwitch = new DigitalInput (QR_PASSING_LIMIT_SWITCH);
	cataLimitSwitch = new DigitalInput (CATA_LIMIT_SWITCH);
	
	// Add to Live Window
	liveWindow();
}

Catapult::~Catapult() {
	delete winchMotor;
	delete releaseMotor;
	delete qrFiringLimitSwitch;
	delete qrPassingLimitSwitch;
	delete cataLimitSwitch;
}

void Catapult::winchRetract() {
	winchMotor->Set(WINCH_RETRACT_SPEED);
}

void Catapult::winchPayout() {
	winchMotor->Set(-WINCH_RETRACT_SPEED);
}

void Catapult::winchStop() {
	winchMotor->Set(0.0);
}

void Catapult::qrStart() {
	releaseMotor->Set(-1.0);
}

void Catapult::qrStop() {
	releaseMotor->Set(0.0);
}

bool Catapult::qrFiringSwitchPressed() {
	return qrFiringLimitSwitch->Get()==0;
}

bool Catapult::qrPassingSwitchPressed() {
	return qrPassingLimitSwitch->Get()==0;
}

bool Catapult::cataLimitSwitchPressed() {
	return cataLimitSwitch->Get()==0;
}

void Catapult::liveWindow() {
	// Add all off the components to the Live Window for testing
	LiveWindow* lw = LiveWindow::GetInstance();
	lw->AddActuator("Catapult", "Release Motor", releaseMotor);
	lw->AddActuator("Catapult", "Winch Motor", winchMotor);
}
