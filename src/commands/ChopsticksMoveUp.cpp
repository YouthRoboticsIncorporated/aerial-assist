#include "ChopsticksMoveUp.h"
#include "../Robotmap.h"

ChopsticksMoveUp::ChopsticksMoveUp():CommandBase("ChopsticksMoveUp"){
	Requires(forklift);
	Requires(chopsticks);
}

void ChopsticksMoveUp::Initialize(){
	chopsticks->spinChopsticks(CHOPSTICKS_ROTATE_SPEED);	
}

void ChopsticksMoveUp::Execute(){
	forklift->moveForklift(CHOPSTICKS_MOVE_UP_SPEED);
}

bool ChopsticksMoveUp::IsFinished(){
    return false;
}

void ChopsticksMoveUp::End(){
}

void ChopsticksMoveUp::Interrupted(){
	forklift->moveForklift (0.0);
}	
