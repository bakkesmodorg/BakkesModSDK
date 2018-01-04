#pragma once
#include "../wrapperstructs.h"
#include "../actorwrapper.h"

class BAKKESMOD_PLUGIN_IMPORT WheelWrapper : public ActorWrapper
{

public:
	CONSTRUCTORS(WheelWrapper)

		//AUTO GENERATED
		GETSETH(float, SteerFactor)
		GETSETH(float, WheelRadius)
		GETSETH(float, SuspensionStiffness)
		GETSETH(float, SuspensionDampingCompression)
		GETSETH(float, SuspensionDampingRelaxation)
		GETSETH(float, SuspensionTravel)
		GETSETH(float, SuspensionMaxRaise)
		GETSETH(float, SpinSpeedDecayRate)
		GETSETH(Vector, BoneOffset)
		GETSETH(Vector, PresetRestPosition)
		GETSETH(Vector, LocalSuspensionRayStart)
		GETSETH(Vector, LocalRestPosition)
		GETSETH(int, WheelIndex)
		GETSETH(bool, HadContact)
		GETSETH(float, SpinSpeed)

		GETH(Vector, LinearVelocity)
		GETH(float, Steer)
		GETH(float, SuspensionDistance)
		GETH(Vector, RefWheelLocation)

private:
	PIMPL
};

