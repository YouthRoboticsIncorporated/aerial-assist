
#include "ChopsticksStop.h"
#include "../Robotmap.h"

ChopsticksStop::ChopsticksStop():CommandBase("ChopsticksStop"){
	Requires(chopsticks);
}

void ChopsticksStop::Initialize(){	
}

void ChopsticksStop::Execute(){
	chopsticks->spinChopsticks(0.0);
}

bool ChopsticksStop::IsFinished(){
	return false;
}

void ChopsticksStop::End(){
}

void ChopsticksStop::Interrupted(){
	chopsticks->spinChopsticks (0.0);
}	
