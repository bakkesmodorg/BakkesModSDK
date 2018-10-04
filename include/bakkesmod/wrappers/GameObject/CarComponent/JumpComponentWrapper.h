#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/CarComponent/CarComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT JumpComponentWrapper : public CarComponentWrapper {
public:
	CONSTRUCTORS(JumpComponentWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetMinJumpTime();
	void SetMinJumpTime(float newMinJumpTime);
	float GetJumpImpulse();
	void SetJumpImpulse(float newJumpImpulse);
	float GetJumpForce();
	void SetJumpForce(float newJumpForce);
	float GetJumpForceTime();
	void SetJumpForceTime(float newJumpForceTime);
	float GetPodiumJumpForceTime();
	void SetPodiumJumpForceTime(float newPodiumJumpForceTime);
	float GetJumpImpulseSpeed();
	void SetJumpImpulseSpeed(float newJumpImpulseSpeed);
	float GetJumpAccel();
	void SetJumpAccel(float newJumpAccel);
	float GetMaxJumpHeight();
	void SetMaxJumpHeight(float newMaxJumpHeight);
	float GetMaxJumpHeightTime();
	void SetMaxJumpHeightTime(float newMaxJumpHeightTime);
	unsigned long GetbDeactivate();
	void SetbDeactivate(unsigned long newbDeactivate);

	//AUTO-GENERATED FUNCTION PROXIES
	void ApplyForces(float ActiveTime);
	void CacheJumpData();
	void OnCreated();
private:
	PIMPL
};