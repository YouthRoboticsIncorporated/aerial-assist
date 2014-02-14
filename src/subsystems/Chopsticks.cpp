#include "Chopsticks.h"
#include "../Robotmap.h"

Chopsticks::Chopsticks():Subsystem("Chopsticks"){
    chopsticksmotor = new Victor (CHOPSTICK_MOTOR_PWM);
}

Chopsticks::~Chopsticks() {
	delete chopsticksmotor;
}

void Chopsticks::spinChopsticks(double speed) {
	chopsticksmotor->Set(speed); 
	
}
