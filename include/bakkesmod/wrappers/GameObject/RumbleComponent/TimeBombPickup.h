#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT TimeBombPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(TimeBombPickup)

	//AUTO-GENERATED FROM FIELDS
	float GetRadius();
	void SetRadius(float newRadius);
	float GetAlmostReadyDuration();
	void SetAlmostReadyDuration(float newAlmostReadyDuration);
	float GetStartMatSpeed();
	void SetStartMatSpeed(float newStartMatSpeed);
	float GetAlmostReadyMatSpeed();
	void SetAlmostReadyMatSpeed(float newAlmostReadyMatSpeed);
	float GetImpulseForce();
	void SetImpulseForce(float newImpulseForce);
	float GetCarVerticalForce();
	void SetCarVerticalForce(float newCarVerticalForce);
	float GetCarTorque();
	void SetCarTorque(float newCarTorque);
	unsigned long GetbDemolish();
	void SetbDemolish(unsigned long newbDemolish);
	unsigned long GetbImpulse();
	void SetbImpulse(unsigned long newbImpulse);

	//AUTO-GENERATED FUNCTION PROXIES
	void PickupEnd();
	void AlmostReady2();
	void PickupStart();
private:
	PIMPL
};