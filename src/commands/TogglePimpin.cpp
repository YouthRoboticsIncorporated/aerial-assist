#include "TogglePimpin.h"


TogglePimpin :: TogglePimpin(): CommandBase ("TogglePimpin"){
    Requires (chassis);
}

void TogglePimpin::Initialize(){
	chassis->weBePimpin =! chassis->weBePimpin;
}

void TogglePimpin::Execute(){
}

bool TogglePimpin::IsFinished(){
	return true;
}

void TogglePimpin::End(){
		
}

void TogglePimpin::Interrupted(){
}
