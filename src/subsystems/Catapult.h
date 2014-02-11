#ifndef Catapult_h
#define Catapult_h

#include <WPILib.h>

class Catapult: public Subsystem {
	public:
		Catapult();
		~Catapult();
		void winchRetract();
		void winchPayout();
		void winchStop();
		void qrStart();
		void qrStop();
		bool qrPassingSwitchPressed();
		bool qrFiringSwitchPressed();
		bool cataLimitSwitchPressed();
		
		
	private:
		Victor* releaseMotor;
		Victor* winchMotor;
		DigitalInput* qrFiringLimitSwitch;
		DigitalInput* qrPassingLimitSwitch;
		DigitalInput* cataLimitSwitch;
		
};
#endif
