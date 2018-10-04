#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/CarComponent/CarComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT AirControlComponentWrapper : public CarComponentWrapper {
public:
	CONSTRUCTORS(AirControlComponentWrapper)

	//AUTO-GENERATED FROM FIELDS
	Rotator GetAirTorque();
	void SetAirTorque(Rotator newAirTorque);
	Rotator GetAirDamping();
	void SetAirDamping(Rotator newAirDamping);
	float GetThrottleForce();
	void SetThrottleForce(float newThrottleForce);
	float GetDodgeDisableTimeRemaining();
	void SetDodgeDisableTimeRemaining(float newDodgeDisableTimeRemaining);
	float GetControlScale();
	void SetControlScale(float newControlScale);
	float GetAirControlSensitivity();
	void SetAirControlSensitivity(float newAirControlSensitivity);

	//AUTO-GENERATED FUNCTION PROXIES
	void ApplyForces(float ActiveTime);
	void OnCreated();
private:
	PIMPL
};