#pragma once
#include "actorwrapper.h"
#include "wrapperstructs.h"
class BAKKESMOD_PLUGIN_IMPORT CameraWrapper
{
public:
	CONSTRUCTORS(CameraWrapper)

	Vector GetLocation();
	void SetLocation(Vector location);

	Rotator GetRotation();
	void SetRotation(Rotator rotation);
	ProfileCameraSettings GetCameraSettings();
	void SetCameraSettings(ProfileCameraSettings settings);
	bool IsCameraShakeOn();

	POV GetPOV();
	void SetPOV(POV pov); 

	void SetFOV(float fov);
	float GetFOV();
	void SetLockedFOV(bool lock);

	ActorWrapper GetCameraAsActor();
	string GetCameraState();

	Vector linterp(Vector start, Vector end, float elapsed, float speed);
private:
	PIMPL
};

