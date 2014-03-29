#include "AutonomousCommandGroup.h"
#include "DriveForward.h"
#include "ThrowBall.h"
#include "FindPosition.h"
#include "ChopsticksDrop.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential (new DriveForward());
	AddSequential (new ChopsticksDrop());
	//AddSequential (new FindPosition());
	AddSequential (new ThrowBall());
}
