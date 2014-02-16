#include "Beaglebone.h"
#include "../Robotmap.h"
#include "../commands/RunTracking.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>


Beaglebone::Beaglebone():Subsystem ("Beaglebone"){
    ultrasonic = new AnalogChannel(BALL_ULTRASONIC_MODULE, BALL_ULTRASONIC);
    ultrasonic->SetAverageBits(32);
    ultrasonic->SetOversampleBits(32);
    
    ballX = 99.0;
    ballY = 99.0;
    ballDiam = 99.0;
    goalX = 99.0;
    goalY = 99.0;
    goalAngle = 99.0;
    isConnected = false;
    isBound = false;
    isTrackingBall = true;
    
    // Initialise the connection parameters
    // This section opens a UDP connection to the beagle bone
    memset(&address_bbb, 0, sizeof(address_bbb));
    address_bbb.sin_family = AF_INET;
    address_bbb.sin_port = htons(BEAGLEBONE_PORT);
    inet_aton(const_cast<char *>(BEAGLEBONE_IP), &address_bbb.sin_addr);
    sd_bbb = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // To send to BBB

    // This section creates a listening UDP connection on the cRIO
    memset(&address_crio, 0, sizeof(address_crio));
    address_crio.sin_family = AF_INET;
    address_crio.sin_port = htons(BEAGLEBONE_PORT);
    address_crio.sin_addr.s_addr = htonl(INADDR_ANY);
    sd_crio = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // To send receive on cRIO
    struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 10000; // Timeout for connection
	setsockopt(sd_crio, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));
    
    // Try to bind the port
    bindPort();
}

Beaglebone::~Beaglebone() {
    close(sd_crio);
    close(sd_bbb);
}

void Beaglebone::readData() {
    if (!isBound) {
        // Try to connect again
        bindPort();
        return;
    }
    isTrackingBall = ultrasonic->GetAverageVoltage()<BALL_ULTRASONIC_THRESHOLD;
    // Send a UDP blast to the BBB to make sure it is in the correct mode
    char targetCode = 'g';
    if (isTrackingBall) {
        DriverStation::Alliance colour;
	    colour = DriverStation::GetInstance()->GetAlliance();
	    if (colour == DriverStation::Alliance::kBlue){
		    targetCode = 'b';
		}
		else{
			targetCode = 'r';
		}
    }
    sendto(sd_bbb, &targetCode, 1, 0, (struct sockaddr*)&address_bbb, sizeof(address_bbb));
    
    // Create a buffer to receive info into
    char line[256];
    char* lastChar = NULL;
    
    
    // Receive a UDP packet
    int numRead = recvfrom(sd_crio, line, sizeof(line), 0, NULL, NULL);
    
    // Process the packet
    if (numRead > 0) {
        char target = line[0]; // First character tells us if it's goal or ball
        lastChar = &line[1]; // Process numbers from the second character
		double a = strtod(lastChar, &lastChar);
		double b = strtod(lastChar, &lastChar);
		double c = strtod(lastChar, NULL);
        // Store these in the appropriate member variables
        if (target == 'g') {
            goalX = a;
            goalY = b;
            goalAngle = c;
            // Reset the other variables
            ballX = 99.0;
            ballY = 99.0;
            ballDiam = 99.0;
        } else {
            ballX = a;
            ballY = b;
            ballDiam = c;
            goalX = 99.0;
            goalY = 99.0;
            goalAngle = 99.0;
            isConnected = true;
            missedPackets=0;
        }
    } else {
		// We must have timed out
		missedPackets++;
	}
	if (missedPackets > 100) {
		isConnected = false;
	}
}

bool Beaglebone::bindPort() {
    isBound = (bind(sd_crio, (struct sockaddr*)&address_crio,
		sizeof(address_crio)) == -1);
    return isBound;
}

void Beaglebone::InitDefaultCommand() {
    SetDefaultCommand(new RunTracking());
}

double Beaglebone::ballRange() {
	return ultrasonic->GetAverageVoltage();
}

