#pragma once
#include "CameraStates/CameraStateBlenderWrapper.h"
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/CameraXWrapper.h"
class ActorWrapper;
class RBActorWrapper;
class WrapperStructs;

class BAKKESMOD_PLUGIN_IMPORT CameraWrapper : public CameraXWrapper {
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
	std::string GetCameraState();
	void SetCameraState(std::string stateName);
	Vector linterp(Vector start, Vector end, float elapsed, float speed);	//END SELF IMPLEMENTED
	std::string GetFocusActor();
	bool SetFocusActor(std::string actorName);
    bool SetFlyCamBallTargetMode();
	_NODISCARD CameraStateBlenderWrapper GetBlender() const;

	//AUTO-GENERATED FROM FIELDS
	float GetSwivelFastSpeed();
	void SetSwivelFastSpeed(float newSwivelFastSpeed);
	float GetSwivelDieRate();
	void SetSwivelDieRate(float newSwivelDieRate);
	StructArrayWrapper<ProfileCameraSettings> GetCameraPresetSettings();
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