#include "Chopsticks.h"
#include "../Robotmap.h"

Chopsticks::Chopsticks():Subsystem("Chopsticks"){
    chopsticksleftmotor = new Victor (CHOPSTICK_LEFT_MOTOR_PWM);
    chopsticksrightmotor = new Victor (CHOPSTICK_RIGHT_MOTOR_PWM);
    
}

Chopsticks::~Chopsticks() {
	delete chopsticksleftmotor;
    delete chopsticksrightmotor;
}

void Chopsticks::spinChopsticks(double speed) {
	chopsticksleftmotor->Set(speed);
    chopsticksrightmotor->Set(speed); 
	
}

