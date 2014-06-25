#include "BallTrap.h"
#include "../Robotmap.h"

BallTrap :: BallTrap(): Subsystem("balltrap") {
    balltrapmotor = new Victor (BALL_TRAP_MOTOR_PWM);
}

BallTrap :: ~BallTrap() {
    delete balltrapmotor;
}

void BallTrap :: moveTrap(double speed) {
    balltrapmotor->Set(speed);
} 
