#pragma once
template<class T> class ArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/CarComponent/CarComponentWrapper.h"
class BoostWrapper;
class RBActorWrapper;
class UnrealStringWrapper;
class BallWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT RumblePickupComponentWrapper : public CarComponentWrapper {
public:
	CONSTRUCTORS(RumblePickupComponentWrapper)

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetPickupName();
	unsigned long GetbHudIgnoreUseTime();
	void SetbHudIgnoreUseTime(unsigned long newbHudIgnoreUseTime);
	unsigned long GetbHasActivated();
	void SetbHasActivated(unsigned long newbHasActivated);
	unsigned long GetbIsActive();
	void SetbIsActive(unsigned long newbIsActive);
	float GetActivationDuration();
	void SetActivationDuration(float newActivationDuration);

	//AUTO-GENERATED FUNCTION PROXIES
	bool HasActivated2();
	RBActorWrapper GetClientTarget();
	void OnVehicleSetupComplete();
	float GetActiveTimePercent();
	void PickupEnd();
	void PickupStart();
	BoostWrapper GetBoostComponent();
	void DeactivatePickup();
	bool TryActivate(RBActorWrapper TargetOverride);
	void OnCreated();
	bool CanPickup(CarWrapper InCar);
	void ApplyPickup(CarWrapper InCar);
private:
	PIMPL
};