#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT BaseCameraWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(BaseCameraWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetDefaultFOV();
	void SetDefaultFOV(float newDefaultFOV);
	unsigned long GetbLockedFOV();
	void SetbLockedFOV(unsigned long newbLockedFOV);
	unsigned long GetbConstrainAspectRatio();
	void SetbConstrainAspectRatio(unsigned long newbConstrainAspectRatio);
	unsigned long GetbEnableFading();
	void SetbEnableFading(unsigned long newbEnableFading);
	unsigned long GetbFadeAudio();
	void SetbFadeAudio(unsigned long newbFadeAudio);
	unsigned long GetbForceDisableTemporalAA();
	void SetbForceDisableTemporalAA(unsigned long newbForceDisableTemporalAA);
	unsigned long GetbEnableColorScaling();
	void SetbEnableColorScaling(unsigned long newbEnableColorScaling);
	unsigned long GetbEnableColorScaleInterp();
	void SetbEnableColorScaleInterp(unsigned long newbEnableColorScaleInterp);
	unsigned long GetbUseClientSideCameraUpdates();
	void SetbUseClientSideCameraUpdates(unsigned long newbUseClientSideCameraUpdates);
	unsigned long GetbDebugClientSideCamera();
	void SetbDebugClientSideCamera(unsigned long newbDebugClientSideCamera);
	unsigned long GetbShouldSendClientSideCameraUpdate();
	void SetbShouldSendClientSideCameraUpdate(unsigned long newbShouldSendClientSideCameraUpdate);
	float GetLockedFOV();
	void SetLockedFOV(float newLockedFOV);
	float GetConstrainedAspectRatio();
	void SetConstrainedAspectRatio(float newConstrainedAspectRatio);
	float GetDefaultAspectRatio();
	void SetDefaultAspectRatio(float newDefaultAspectRatio);
	float GetOffAxisYawAngle();
	void SetOffAxisYawAngle(float newOffAxisYawAngle);
	float GetOffAxisPitchAngle();
	void SetOffAxisPitchAngle(float newOffAxisPitchAngle);
	UnrealColor GetFadeColor();
	void SetFadeColor(UnrealColor newFadeColor);
	float GetFadeAmount();
	void SetFadeAmount(float newFadeAmount);
	float GetCamOverridePostProcessAlpha();
	void SetCamOverridePostProcessAlpha(float newCamOverridePostProcessAlpha);
	Vector GetColorScale();
	void SetColorScale(Vector newColorScale);
	Vector GetDesiredColorScale();
	void SetDesiredColorScale(Vector newDesiredColorScale);
	Vector GetOriginalColorScale();
	void SetOriginalColorScale(Vector newOriginalColorScale);
	float GetColorScaleInterpDuration();
	void SetColorScaleInterpDuration(float newColorScaleInterpDuration);
	float GetColorScaleInterpStartTime();
	void SetColorScaleInterpStartTime(float newColorScaleInterpStartTime);
	ViewTarget GetViewTarget();
	void SetViewTarget(ViewTarget newViewTarget);
	ViewTarget GetPendingViewTarget();
	void SetPendingViewTarget(ViewTarget newPendingViewTarget);
	float GetBlendTimeToGo();
	void SetBlendTimeToGo(float newBlendTimeToGo);
	float GetFreeCamDistance();
	void SetFreeCamDistance(float newFreeCamDistance);
	Vector GetFreeCamOffset();
	void SetFreeCamOffset(Vector newFreeCamOffset);
	float GetFadeTime();
	void SetFadeTime(float newFadeTime);
	float GetFadeTimeRemaining();
	void SetFadeTimeRemaining(float newFadeTimeRemaining);

	//AUTO-GENERATED FUNCTION PROXIES
	void StopAllCameraAnims(unsigned long bImmediate);
	void ClearAllCameraShakes();
	float CalcRadialShakeScale(BaseCameraWrapper Cam, Vector& Epicenter, float InnerRadius, float OuterRadius, float Falloff);
	void ClearCameraLensEffects();
	void ApplyAudioFade();
	void UpdateFade(float DeltaTime);
	void DoUpdateCamera(float DeltaTime);
	void eventUpdateCamera(float DeltaTime);
	void SetDesiredColorScale2(Vector& NewColorScale, float InterpTime);
	Rotator GetCameraRotation();
	void SetFOV(float NewFOV);
	float GetFOVAngle();
	void eventDestroyed();
	void PostBeginPlay();
private:
	PIMPL
};