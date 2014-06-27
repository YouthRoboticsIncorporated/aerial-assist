#include "BallTrapOpen.h"
#include "../Robotmap.h"

BallTrapOpen :: BallTrapOpen(): CommandBase("BallTrapOpen") {
    Requires (balltrap);
}

void BallTrapOpen :: Initialize() {
    balltrap->moveTrap(-BALL_TRAP_MOTOR_SPEED);
}

void BallTrapOpen :: Execute() {
    balltrap->moveTrap(-BALL_TRAP_MOTOR_SPEED);
}

bool BallTrapOpen :: IsFinished() {
  return false;  
}

void BallTrapOpen :: End() {
    
}

void BallTrapOpen :: Interrupted() {
    balltrap->moveTrap(0.0);
}
