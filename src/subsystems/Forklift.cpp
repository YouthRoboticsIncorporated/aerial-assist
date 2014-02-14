#include "Forklift.h"
#include "../Robotmap.h"

Forklift::Forklift():Subsystem("Forklift"){
	verticalmotor = new Victor (VERTICAL_CHOPSTICKS_MOTOR_PWM);
}

Forklift::~Forklift() {
	delete verticalmotor;
}

void Forklift::moveForklift(double speed){
	verticalmotor->Set(speed);
}
