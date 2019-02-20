#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/CarComponent/CarComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT FlipCarComponentWrapper : public CarComponentWrapper {
public:
	CONSTRUCTORS(FlipCarComponentWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetFlipCarImpulse();
	void SetFlipCarImpulse(float newFlipCarImpulse);
	float GetFlipCarTorque();
	void SetFlipCarTorque(float newFlipCarTorque);
	float GetFlipCarTime();
	void SetFlipCarTime(float newFlipCarTime);
	unsigned long GetbFlipRight();
	void SetbFlipRight(unsigned long newbFlipRight);

	//AUTO-GENERATED FUNCTION PROXIES
	void InitFlip();
	void ApplyForces(float ActiveTime);
	bool CanActivate();
	void OnCreated();
private:
	PIMPL
};