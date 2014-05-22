#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>
#include <MPU6050.h>

class Chassis: public Subsystem {
	public:
		Chassis();
		~Chassis();
		void InitDefaultCommand();
		void drive(double vX, double vY, double vR, double throttle, bool weBePimpin = false);
		
	private:
		Victor* driveMotorA;
		Victor* driveMotorB;
		Victor* driveMotorC;
		Victor* driveMotorD;
		void liveWindow();

		Encoder *encoderA, *encoderB, *encoderC, *encoderD;
		
		Gyro *gyro;
        lib4774::MPU6050 *mpu;
};

#endif
