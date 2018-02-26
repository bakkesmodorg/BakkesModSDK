#pragma once
template<class T> class ArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class VehicleSimWrapper;

class BAKKESMOD_PLUGIN_IMPORT WheelWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(WheelWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetSteerFactor();
	void SetSteerFactor(float newSteerFactor);
	float GetWheelRadius();
	void SetWheelRadius(float newWheelRadius);
	float GetSuspensionStiffness();
	void SetSuspensionStiffness(float newSuspensionStiffness);
	float GetSuspensionDampingCompression();
	void SetSuspensionDampingCompression(float newSuspensionDampingCompression);
	float GetSuspensionDampingRelaxation();
	void SetSuspensionDampingRelaxation(float newSuspensionDampingRelaxation);
	float GetSuspensionTravel();
	void SetSuspensionTravel(float newSuspensionTravel);
	float GetSuspensionMaxRaise();
	void SetSuspensionMaxRaise(float newSuspensionMaxRaise);
	float GetSpinSpeedDecayRate();
	void SetSpinSpeedDecayRate(float newSpinSpeedDecayRate);
	Vector GetBoneOffset();
	void SetBoneOffset(Vector newBoneOffset);
	Vector GetPresetRestPosition();
	void SetPresetRestPosition(Vector newPresetRestPosition);
	Vector GetLocalSuspensionRayStart();
	void SetLocalSuspensionRayStart(Vector newLocalSuspensionRayStart);
	Vector GetLocalRestPosition();
	void SetLocalRestPosition(Vector newLocalRestPosition);
	VehicleSimWrapper GetVehicleSim();
	void SetVehicleSim(VehicleSimWrapper newVehicleSim);
	int GetWheelIndex();
	void SetWheelIndex(int newWheelIndex);
	unsigned long GetbDrawDebug();
	void SetbDrawDebug(unsigned long newbDrawDebug);
	unsigned long GetbHadContact();
	void SetbHadContact(unsigned long newbHadContact);
	float GetFrictionCurveInput();
	void SetFrictionCurveInput(float newFrictionCurveInput);
	float GetSpinSpeed();
	void SetSpinSpeed(float newSpinSpeed);

	//AUTO-GENERATED FUNCTION PROXIES
	Vector GetRefWheelLocation();
	float GetSuspensionDistance();
	float GetSteer2();
	Vector GetLinearVelocity();
	void EventContactChanged(WheelWrapper Wheel);
private:
	PIMPL
};