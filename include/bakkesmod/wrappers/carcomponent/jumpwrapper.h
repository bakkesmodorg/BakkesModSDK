#pragma once
#include "../wrapperstructs.h"
#include "../actorwrapper.h"

#include "carcomponentwrapper.h"
class BAKKESMOD_PLUGIN_IMPORT JumpWrapper : public CarComponentWrapper
{

public:
	CONSTRUCTORS(JumpWrapper)

		//AUTO GENERATED
		GETSETH(float, MinJumpTime)
		GETSETH(float, JumpImpulse)
		GETSETH(float, JumpForce)
		GETSETH(float, JumpForceTime)
		GETSETH(float, PodiumJumpForceTime)
		GETSETH(float, JumpImpulseSpeed)
		GETSETH(float, JumpAccel)
		GETSETH(float, MaxJumpHeight)

		GETSETH(float, MaxJumpHeightTime)
		GETSETH(bool, WillDeactivate)

		bool IsJumping();

private:
	PIMPL
};

