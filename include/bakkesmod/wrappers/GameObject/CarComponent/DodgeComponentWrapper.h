#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/CarComponent/CarComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT DodgeComponentWrapper : public CarComponentWrapper {
public:
	CONSTRUCTORS(DodgeComponentWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetDodgeInputThreshold();
	void SetDodgeInputThreshold(float newDodgeInputThreshold);
	float GetSideDodgeImpulse();
	void SetSideDodgeImpulse(float newSideDodgeImpulse);
	float GetSideDodgeImpulseMaxSpeedScale();
	void SetSideDodgeImpulseMaxSpeedScale(float newSideDodgeImpulseMaxSpeedScale);
	float GetForwardDodgeImpulse();
	void SetForwardDodgeImpulse(float newForwardDodgeImpulse);
	float GetForwardDodgeImpulseMaxSpeedScale();
	void SetForwardDodgeImpulseMaxSpeedScale(float newForwardDodgeImpulseMaxSpeedScale);
	float GetBackwardDodgeImpulse();
	void SetBackwardDodgeImpulse(float newBackwardDodgeImpulse);
	float GetBackwardDodgeImpulseMaxSpeedScale();
	void SetBackwardDodgeImpulseMaxSpeedScale(float newBackwardDodgeImpulseMaxSpeedScale);
	float GetSideDodgeTorque();
	void SetSideDodgeTorque(float newSideDodgeTorque);
	float GetForwardDodgeTorque();
	void SetForwardDodgeTorque(float newForwardDodgeTorque);
	float GetDodgeTorqueTime();
	void SetDodgeTorqueTime(float newDodgeTorqueTime);
	float GetMinDodgeTorqueTime();
	void SetMinDodgeTorqueTime(float newMinDodgeTorqueTime);
	float GetDodgeZDamping();
	void SetDodgeZDamping(float newDodgeZDamping);
	float GetDodgeZDampingDelay();
	void SetDodgeZDampingDelay(float newDodgeZDampingDelay);
	float GetDodgeZDampingUpTime();
	void SetDodgeZDampingUpTime(float newDodgeZDampingUpTime);
	float GetDodgeImpulseScale();
	void SetDodgeImpulseScale(float newDodgeImpulseScale);
	float GetDodgeTorqueScale();
	void SetDodgeTorqueScale(float newDodgeTorqueScale);
	Vector GetDodgeTorque();
	void SetDodgeTorque(Vector newDodgeTorque);
	Vector GetDodgeDirection();
	void SetDodgeDirection(Vector newDodgeDirection);

	//AUTO-GENERATED FUNCTION PROXIES
	void SetDodgeSettings();
	void ApplyTorqueForces(float ActiveTime);
	void ApplyDodgeImpulse();
	Vector GetDodgeImpulse2(Vector& DodgeDir);
	void ApplyForces(float ActiveTime);
	bool CanActivate();
	void OnCreated();
private:
	PIMPL
};