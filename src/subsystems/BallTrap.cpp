#include "BallTrap.h"
#include "../Robotmap.h"

BallTrap :: BallTrap(): Subsystem("balltrap") {
    leftballtrapmotor = new Victor (BALL_TRAP_LEFT_MOTOR_PWM);
    rightballtrapmotor = new Victor (BALL_TRAP_RIGHT_MOTOR_PWM);
}

BallTrap :: ~BallTrap() {
    delete leftballtrapmotor;
    delete rightballtrapmotor;
}

void BallTrap :: moveTrap(double speed) {
    leftballtrapmotor->Set(speed);
    rightballtrapmotor->Set(speed);
} 
