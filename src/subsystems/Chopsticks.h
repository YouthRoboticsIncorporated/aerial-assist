#ifndef Chopsticks_h
#define Chopsticks_h

#include <WPILib.h>

class Chopsticks: public Subsystem {
	public:
		Chopsticks();
		~Chopsticks();
		void spinChopsticks(double speed);
		
	private:
		Victor* chopsticksmotor;
};

#endif
