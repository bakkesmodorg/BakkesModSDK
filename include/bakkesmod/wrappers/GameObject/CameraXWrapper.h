#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/BaseCameraWrapper.h"
class ActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT CameraXWrapper : public BaseCameraWrapper {
public:
	CONSTRUCTORS(CameraXWrapper)

	//AUTO-GENERATED FROM FIELDS
	Rotator GetPCDeltaRotation();
	void SetPCDeltaRotation(Rotator newPCDeltaRotation);
	Rotator GetOldControllerRotation();
	void SetOldControllerRotation(Rotator newOldControllerRotation);
	Vector GetPCDeltaLocation();
	void SetPCDeltaLocation(Vector newPCDeltaLocation);
	Vector GetOldControllerLocation();
	void SetOldControllerLocation(Vector newOldControllerLocation);
	Vector GetShakeLocationOffset();
	void SetShakeLocationOffset(Vector newShakeLocationOffset);
	Rotator GetShakeRotationOffset();
	void SetShakeRotationOffset(Rotator newShakeRotationOffset);
	float GetShakeFOVOffset();
	void SetShakeFOVOffset(float newShakeFOVOffset);
	UnrealColor GetStartFadeColor();
	void SetStartFadeColor(UnrealColor newStartFadeColor);
	UnrealColor GetEndFadeColor();
	void SetEndFadeColor(UnrealColor newEndFadeColor);
	Vector GetClipOffset();
	void SetClipOffset(Vector newClipOffset);
	unsigned long GetbDisableCameraShake();
	void SetbDisableCameraShake(unsigned long newbDisableCameraShake);
	unsigned long GetbSnapNextTransition();
	void SetbSnapNextTransition(unsigned long newbSnapNextTransition);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventOnViewTargetChanged();
	bool IsTransitioning();
	void SnapTransition();
	void CopyFade(CameraXWrapper Other);
	void UpdateFade(float DeltaTime);
	void eventUpdateCamera(float DeltaTime);
	Rotator RemoveRoll(Rotator& InRot);
	void UpdateCameraState();
	void InstanceCameraStates();
	void OnLoadingMovieClosesd();
	void eventPostBeginPlay();
private:
	PIMPL
};