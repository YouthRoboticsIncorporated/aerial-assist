#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>
#include <MPU6050.h>
#include "GyroCorrection.h"

class Chassis: public Subsystem {
	public:
		Chassis();
		~Chassis();
		void InitDefaultCommand();
		void drive(double vX, double vY, double vR, double throttle, bool weBePimpin = false);
		Victor* driveMotorA;
		Victor* driveMotorB;
		Victor* driveMotorC;
		Victor* driveMotorD;
        
	private:
		
		void liveWindow();

		Encoder *encoderA, *encoderB; //*encoderC, *encoderD;
		
		Gyro *gyro;
        GyroCorrection *correction;
        PIDController *gyro_pid;
        //lib4774::MPU6050 *mpu;
        int loopcounter;
        double accX, accY, accZ, gyroX, gyroY, gyroZ;
};

#endif
