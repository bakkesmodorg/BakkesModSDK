#pragma once
#include "CameraStateCarRefWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT CameraStateCarWrapper : public CameraStateCarRefWrapper
{
public:
	CONSTRUCTORS(CameraStateCarWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	static const CameraStateCarWrapper GetInstanceWithDefaultValues();
	//END SELF IMPLEMENTED

	_NODISCARD float GetInterpToGroundRate() const;
	_NODISCARD float GetInterpToAirRate() const;
	_NODISCARD float GetGroundRotationInterpRate() const;
	_NODISCARD float GetGroundRotationInterpRateWall() const;
	_NODISCARD float GetFOVInterpSpeed() const;
	_NODISCARD float GetSupersonicFOVInterpSpeed() const;
	_NODISCARD float GetGroundNormalInterpRate() const;

	void SetInterpToGroundRate(float value);
	void SetInterpToAirRate(float value);
	void SetGroundRotationInterpRate(float value);
	void SetGroundRotationInterpRateWall(float value);
	void SetFOVInterpSpeed(float value);
	void SetSupersonicFOVInterpSpeed(float value);
	void SetGroundNormalInterpRate(float value);

private:
	PIMPL
	
};
