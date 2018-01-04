#pragma once
#include "actorwrapper.h"
#include "wrapperstructs.h"
#include "arraywrapper.h"
class WheelWrapper;
class BAKKESMOD_PLUGIN_IMPORT VehicleSimWrapper : public ActorWrapper
{
public:
	CONSTRUCTORS(VehicleSimWrapper)

		//AUTO GENERATED
		GETSETH(float, DriveTorque)
		GETSETH(float, BrakeTorque)


		GETSETH(float, StopThreshold)
		GETSETH(float, IdleBrakeFactor)
		GETSETH(float, OppositeBrakeFactor)
		GETSETH(bool, UseAckermannSteering)
		ArrayWrapper<WheelWrapper> GetWheels();
private:
	PIMPL
};
