#pragma once
#include "ActorWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT WorldInfoWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(WorldInfoWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetTimeDilation();
	float GetDemoPlayTimeDilation();
	float GetTimeSeconds();
	float GetRealTimeSeconds();
	float GetRealDeltaSeconds();
	float GetAudioTimeSeconds();
	float GetDeltaSeconds();
	float GetPauseDelay();
	float GetRealTimeToUnPause();
	float GetStallZ();
	float GetWorldGravityZ();
	float GetDefaultGravityZ();
	float GetGlobalGravityZ();
	float GetRBPhysicsGravityScaling();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};