#include "ChopsticksDrop.h"
#include "../Robotmap.h"

ChopsticksDrop::ChopsticksDrop():CommandBase("ChopsticksDrop"){
	Requires(forklift);
	SetTimeout(0.1);
}

void ChopsticksDrop::Initialize(){	
	forklift->moveForklift(CHOPSTICKS_MOVE_DOWN_SPEED);
}

void ChopsticksDrop::Execute(){
	
}

bool ChopsticksDrop::IsFinished(){
	return IsTimedOut();
}

void ChopsticksDrop::End(){
	forklift->moveForklift(0);
}

void ChopsticksDrop::Interrupted(){
	chopsticks->spinChopsticks (0.0);
}	
