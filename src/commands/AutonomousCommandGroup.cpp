#include "AutonomousCommandGroup.h"
#include "DriveForward.h"
#include "ThrowBall.h"
#include "FindPosition.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential (new DriveForward());
	//AddSequential (new FindPosition());
	AddSequential (new ThrowBall());
}
