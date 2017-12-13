#pragma once
#include "../wrapperstructs.h"
#include "../actorwrapper.h"

#include "carcomponentwrapper.h"
class BAKKESMOD_PLUGIN_IMPORT DoubleJumpWrapper : public CarComponentWrapper
{

public:
	CONSTRUCTORS(DoubleJumpWrapper)

		//AUTO GENERATED
		GETSETH(float, JumpImpulse)
		GETSETH(float, ImpulseScale)

		bool IsDoubleJumping();

private:
	PIMPL
};

