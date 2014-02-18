#ifndef Beaglebone_h
#define Beaglebone_h

#include <WPILib.h>

class Beaglebone: public Subsystem{
	public:
		Beaglebone();
		~Beaglebone();
		void readData();
		double ballX, ballY, ballDiam, goalRange, goalAngle, goalHot;
		bool isConnected;
		bool isTrackingBall;
		void InitDefaultCommand();
		double ballRange();
						
	private:
		bool bindPort();
        int sd_crio, sd_bbb; // UDP connection file handle
	    struct sockaddr_in address_crio; // Address struct for cRIO
	    struct sockaddr_in address_bbb; // BBB address
	    bool isBound; // Whether we managed to bind with the BBB
	    unsigned int missedPackets;
	    AnalogChannel* ultrasonic;
};


#endif
