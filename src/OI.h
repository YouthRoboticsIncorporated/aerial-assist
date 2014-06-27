#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* joyDrv;
	Joystick* joyOpr;
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
	Button* chopsticksStopButtonOpr;
	Button* retractButtonOpr;
	Button* payoutButtonOpr;
	Button* chopsticksMoveUpButtonOpr;
    Button* ballTrapCloseButtonOpr;
    Button* ballTrapOpenButtonOpr;
    Button* pimpButton;
	

public:
	OI();
	
	Joystick* getJoyDrv();
	Joystick* getJoyOpr();
	double getJoyDrvX();
	double getJoyDrvY();
	double getJoyDrvZ();
	double getJoyDrvThrottle();
};

#endif
