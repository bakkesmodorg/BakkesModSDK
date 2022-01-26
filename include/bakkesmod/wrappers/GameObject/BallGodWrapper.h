#pragma once
#include "BallWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT BallGodWrapper : public BallWrapper {
public:
	CONSTRUCTORS(BallGodWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetWallBounceSpeed();
	void SetWallBounceSpeed(float WallBounceSpeed);
	float GetWallBounceBlend();
	void SetWallBounceBlend(float WallBounceBlend);
	float GetWallBounceBackDistance();
	void SetWallBounceBackDistance(float WallBounceBackDistance);
	float GetTargetBlendScaleXY();
	void SetTargetBlendScaleXY(float TargetBlendScaleXY);
	float GetTargetBlendScaleZ();
	void SetTargetBlendScaleZ(float TargetBlendScaleZ);
	float GetTargetSpeed();
	void SetTargetSpeed(float TargetSpeed);
	float GetTargetSpeedIncrement();
	void SetTargetSpeedIncrement(float TargetSpeedIncrement);
	float GetTargetSpeedBlend();
	void SetTargetSpeedBlend(float TargetSpeedBlend);
	float GetMaxVelocityPitch();
	void SetMaxVelocityPitch(float MaxVelocityPitch);
	float GetLastSpeedIncrementTime();
	void SetLastSpeedIncrementTime(float LastSpeedIncrementTime);
	float GetTargetSpeedIncrementTime();
	void SetTargetSpeedIncrementTime(float TargetSpeedIncrementTime);
	float GetMinGlowBrightness();
	void SetMinGlowBrightness(float MinGlowBrightness);
	float GetMaxGlowBrightness();
	void SetMaxGlowBrightness(float MaxGlowBrightness);
	float GetPulseSpeedScale();
	void SetPulseSpeedScale(float PulseSpeedScale);
	float GetPulseBrightnessScale();
	void SetPulseBrightnessScale(float PulseBrightnessScale);
	float GetPulseMinBrightness();
	void SetPulseMinBrightness(float PulseMinBrightness);
	float GetPulseLifetime();
	void SetPulseLifetime(float PulseLifetime);
	LinearColor GetGlowDefaultColor();
	void SetGlowDefaultColor(LinearColor GlowDefaultColor);
	LinearColor GetMaxSpeedColor();
	void SetMaxSpeedColor(LinearColor MaxSpeedColor);
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	Vector GetDirectionToTarget();
	Vector GetAimLocation();
	LinearColor GetMaxSpeedColor2();
	bool AtMaxSpeed();
	float GetGlowBrightness();
	float GetTargetSpeedAlpha();
	void UpdatePulse();
	void OnTargetSpeedChanged();
	void TryIncrementTargetSpeed();
	void UpdateColor();
	void OnHitTeamNumChanged();
	void SetCarHitTeamNum(unsigned char TeamNum);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};