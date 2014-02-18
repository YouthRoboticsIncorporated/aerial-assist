#include "AutonomousCommandGroup.h"
#include "DriveForward.h"
#include "ThrowBall.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential (new DriveForward());
	AddSequential (new FindPosition());
	AddSequential (new ThrowBall());
}
