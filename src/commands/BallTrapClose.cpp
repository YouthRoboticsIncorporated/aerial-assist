#include "BallTrapClose.h"
#include "../Robotmap.h"

BallTrapClose :: BallTrapClose(): CommandBase("BallTrapClose") {
    Requires (balltrap);
}

void BallTrapClose :: Initialize() {
    balltrap->moveLeftTrap(BALL_TRAP_LEFT_MOTOR_SPEED);
    balltrap->moveRightTrap(BALL_TRAP_RIGHT_MOTOR_SPEED);
}

void BallTrapClose :: Execute() {
    balltrap->moveLeftTrap(BALL_TRAP_LEFT_MOTOR_SPEED);
    balltrap->moveRightTrap(BALL_TRAP_RIGHT_MOTOR_SPEED);
}

bool BallTrapClose :: IsFinished() {
  return false;  
}

void BallTrapClose :: End() {
    
}

void BallTrapClose :: Interrupted() {
    balltrap->moveLeftTrap(0.0);
    balltrap->moveRightTrap(0.0);
}
