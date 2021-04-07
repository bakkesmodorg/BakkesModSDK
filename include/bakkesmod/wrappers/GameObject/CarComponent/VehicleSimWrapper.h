#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class VehicleWrapper;
class CarWrapper;
class WheelWrapper;

class BAKKESMOD_PLUGIN_IMPORT VehicleSimWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(VehicleSimWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	ArrayWrapper<WheelWrapper> GetWheels();
	float GetDriveTorque();
	void SetDriveTorque(float newDriveTorque);
	float GetBrakeTorque();
	void SetBrakeTorque(float newBrakeTorque);
	float GetStopThreshold();
	void SetStopThreshold(float newStopThreshold);
	float GetIdleBrakeFactor();
	void SetIdleBrakeFactor(float newIdleBrakeFactor);
	float GetOppositeBrakeFactor();
	void SetOppositeBrakeFactor(float newOppositeBrakeFactor);
	unsigned long GetbUseAckermannSteering();
	void SetbUseAckermannSteering(unsigned long newbUseAckermannSteering);
	unsigned long GetbWasAttached();
	void SetbWasAttached(unsigned long newbWasAttached);
	float GetOutputThrottle();
	void SetOutputThrottle(float newOutputThrottle);
	float GetOutputSteer();
	void SetOutputSteer(float newOutputSteer);
	float GetOutputBrake();
	void SetOutputBrake(float newOutputBrake);
	float GetOutputHandbrake();
	void SetOutputHandbrake(float newOutputHandbrake);
	VehicleWrapper GetVehicle();
	void SetVehicle(VehicleWrapper newVehicle);
	CarWrapper GetCar();
	void SetCar(CarWrapper newCar);
	float GetSteeringSensitivity();
	void SetSteeringSensitivity(float newSteeringSensitivity);

	//AUTO-GENERATED FUNCTION PROXIES
private:
	PIMPL
};