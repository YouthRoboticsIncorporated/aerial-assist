#include "Beaglebone.h"
#include "../Robotmap.h"

#include <cstdlib>

Beaglebone::Beaglebone():Subsystem ("Beaglebone"){
	
}

Beaglebone::~Beaglebone() {
	
}

void Beaglebone::connect() {
		//this section opens a TCP connection to the beagle bone
	TCPConnector* connector = new TCPConnector();
	TCPStream* stream = connector->connect(BALL_VISION_IP,BALL_VISION_PORT);
	
	
	
}

void Beaglebone::findGoal() {
	
}

void Beaglebone::findBall() {
	if(stream){
		
		
		char line[256];
		char* lastChar = NULL;
		
		stream->send("L", 1);
		stream->receive(line, sizeof(line));
		//this code gets the data from the beagle bone and converts into the following 
		// values so that the robot tracks and follows the ball
		double x = strtod(line, &lastChar);
		if (x <= 1.0 && x >= -1.0) {
			double y = strtod(lastChar, &lastChar);
			double width = strtod(lastChar, NULL);
			double throttle =1.0-0.5*width;
			// chassis->drive(-y,-x,0.0,throttle);
		
		}
		delete stream;
	}
	if (connector) {
		delete connector;
	}
}

