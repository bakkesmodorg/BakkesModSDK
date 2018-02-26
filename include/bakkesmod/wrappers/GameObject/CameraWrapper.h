#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"
class RBActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT CameraWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(CameraWrapper)

	//BEGIN SELF IMPLEMENTED
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
	Vector linterp(Vector start, Vector end, float elapsed, float speed);	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetSwivelFastSpeed();
	void SetSwivelFastSpeed(float newSwivelFastSpeed);
	float GetSwivelDieRate();
	void SetSwivelDieRate(float newSwivelDieRate);
	float GetHorizontalSplitscreenHeightOffset();
	void SetHorizontalSplitscreenHeightOffset(float newHorizontalSplitscreenHeightOffset);
	float GetHorizontalSplitscreenFOVOffset();
	void SetHorizontalSplitscreenFOVOffset(float newHorizontalSplitscreenFOVOffset);
	float GetVerticalSplitscreenFOVOffset();
	void SetVerticalSplitscreenFOVOffset(float newVerticalSplitscreenFOVOffset);
	float GetClipRate();
	void SetClipRate(float newClipRate);
	Rotator GetCurrentSwivel();
	void SetCurrentSwivel(Rotator newCurrentSwivel);
	RBActorWrapper GetDemolisher();
	void SetDemolisher(RBActorWrapper newDemolisher);
	unsigned long GetbDemolished();
	void SetbDemolished(unsigned long newbDemolished);

	//AUTO-GENERATED FUNCTION PROXIES
	float ClipToField(float CameraLocationZ);
	void Demolished2(RBActorWrapper InDemolisher);
	Rotator GetDesiredSwivel(float LookUp, float LookRight);
	void UpdateSwivel(float DeltaTime);
	float GetDefaultFOVOffset();
	float GetDefaultViewHeightOffset();
	void UpdateFOV();
	void EventCameraTargetChanged(CameraWrapper Camera, ActorWrapper Target);
private:
	PIMPL
};