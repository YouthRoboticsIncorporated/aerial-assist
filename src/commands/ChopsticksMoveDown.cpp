#include "ChopsticksMoveDown.h"
#include "../Robotmap.h"

ChopsticksMoveDown::ChopsticksMoveDown():CommandBase("ChopsticksMoveDown"){
	Requires(forklift);
	Requires(chopsticks);
}

void ChopsticksMoveDown::Initialize(){
	chopsticks->spinChopsticks(CHOPSTICKS_ROTATE_SPEED);
}

void ChopsticksMoveDown::Execute(){
	forklift->moveForklift(CHOPSTICKS_MOVE_DOWN_SPEED);
}

bool ChopsticksMoveDown::IsFinished(){
	return forklift->encoder->Get() > FORKLIFT_STOP;
}

void ChopsticksMoveDown::End(){
}

void ChopsticksMoveDown::Interrupted(){
	forklift->moveForklift (0.0);
}	

