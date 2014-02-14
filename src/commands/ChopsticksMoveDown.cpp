#include "ChopsticksMoveDown.h"
#include "../Robotmap.h"

ChopsticksMoveDown::ChopsticksMoveDown():CommandBase("ChopsticksMoveDown"){
	Requires(forklift);
}

void ChopsticksMoveDown::Initialize(){	
}

void ChopsticksMoveDown::Execute(){
	forklift->moveForklift(CHOPSTICKS_MOVE_DOWN_SPEED);
}

bool ChopsticksMoveDown::IsFinished(){
	return false;
}

void ChopsticksMoveDown::End(){
}

void ChopsticksMoveDown::Interrupted(){
	forklift->moveForklift (0.0);
}	

