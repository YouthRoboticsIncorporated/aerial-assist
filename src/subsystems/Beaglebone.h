#ifndef Beaglebone_h
#define Beaglebone_h

#include "../net/tcpconnector.h"

#include <WPILib.h>

class Beaglebone: public Subsystem{
	public:
		Beaglebone();
		~Beaglebone();
		void connect();
		void findGoal();
		void findBall();
		
	private:
		TCPConnector* connector;
		TCPStream* stream;
	
};


#endif
