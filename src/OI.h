#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* joyDrv;
	Button* catchButton;
	Button* chopsticksStopButton;
	Button* chopsticksMoveUpButton;
	Button* chopsticksMoveDownButton;
	Button* throwButton;
	Button* retractButton;
	Button* payoutButton;
	double applyDeadZone(double,double);
	Button* winchOpenButton;
	Button* qrCloseButton;
	Button* passButton;
	

public:
	OI();
	
	Joystick* getJoyDrv();
	double getJoyDrvX();
	double getJoyDrvY();
	double getJoyDrvZ();
	double getJoyDrvThrottle();
	bool weBePimpin();
};

#endif
