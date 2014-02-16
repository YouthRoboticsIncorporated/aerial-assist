#ifndef Catapult_h
#define Catapult_h

#include <WPILib.h>
#include "../Robotmap.h"

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
#ifndef IR_DEBUG
		Counter* winchCounter;
		AnalogTrigger* lineCounterTrigger;
#else
		AnalogChannel* irSensor;
#endif
					
	private:
		Victor* releaseMotor;
		Victor* winchMotor;
		DigitalInput* qrFiringLimitSwitch;
		DigitalInput* qrPassingLimitSwitch;
		DigitalInput* cataLimitSwitch;
		void liveWindow();

};
#endif
