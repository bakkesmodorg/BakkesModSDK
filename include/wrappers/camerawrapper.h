#pragma once
#include "actorwrapper.h"
#include "wrapperstructs.h"
class BAKKESMOD_PLUGIN_IMPORT CameraWrapper
{
public:
	CameraWrapper(std::uintptr_t mem);
	CameraWrapper(const CameraWrapper& other);
	CameraWrapper& operator=(CameraWrapper rhs);
	~CameraWrapper();

	Vector GetLocation();
	void SetLocation(Vector location);

	Rotator GetRotation();
	void SetRotation(Rotator rotation);
	ProfileCameraSettings GetCameraSettings();
	bool IsCameraShakeOn();

	POV GetPOV();
	void SetPOV(POV pov); 

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

