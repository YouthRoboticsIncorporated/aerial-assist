#include "Forklift.h"
#include "../Robotmap.h"

Forklift::Forklift():Subsystem("Forklift"){
	verticalmotor = new Victor (VERTICAL_CHOPSTICKS_MOTOR_PWM);
    encoder = new Encoder (CHOPSTICKS_ENCODER_1, CHOPSTICKS_ENCODER_2);
    
    encoder->Reset();
    
    encoder->Start();
    
    SmartDashboard::PutNumber("Chopstick count", encoder->Get());
}

Forklift::~Forklift() {
	delete verticalmotor;
    delete encoder;
}

void Forklift::moveForklift(double speed){
	verticalmotor->Set(speed);
}


