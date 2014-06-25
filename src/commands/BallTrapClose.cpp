#include "BallTrapClose.h"
#include "../Robotmap.h"

BallTrapClose :: BallTrapClose(): CommandBase("BallTrapClose") {
    Requires (balltrap);
}

void BallTrapClose :: Initialize() {
    balltrap->moveTrap(BALL_TRAP_MOTOR_SPEED);
}

void BallTrapClose :: Execute() {
    balltrap->moveTrap(BALL_TRAP_MOTOR_SPEED);
}

bool BallTrapClose :: IsFinished() {
  return false;  
}

void BallTrapClose :: End() {
    
}

void BallTrapClose :: Interrupted() {
    balltrap->moveTrap(0.0);
}
