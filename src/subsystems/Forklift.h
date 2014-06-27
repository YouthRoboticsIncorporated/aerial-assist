#ifndef Forklift_h
#define Forklift_h

#include <WPILib.h>

class Forklift: public Subsystem {
	public:
		Forklift();
		~Forklift();
		void moveForklift(double speed);
        
		
	private:
		Victor* verticalmotor;
        
};

#endif
