#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class CarWrapper;
class RBActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT TargetedPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(TargetedPickup)

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbCanTargetBall();
	void SetbCanTargetBall(unsigned long newbCanTargetBall);
	unsigned long GetbCanTargetCars();
	void SetbCanTargetCars(unsigned long newbCanTargetCars);
	unsigned long GetbCanTargetEnemyCars();
	void SetbCanTargetEnemyCars(unsigned long newbCanTargetEnemyCars);
	unsigned long GetbCanTargetTeamCars();
	void SetbCanTargetTeamCars(unsigned long newbCanTargetTeamCars);
	unsigned long GetbUseDirectionalTargeting();
	void SetbUseDirectionalTargeting(unsigned long newbUseDirectionalTargeting);
	unsigned long GetbRequireTrace();
	void SetbRequireTrace(unsigned long newbRequireTrace);
	float GetRange();
	void SetRange(float newRange);
	float GetDirectionalTargetingAccuracy();
	void SetDirectionalTargetingAccuracy(float newDirectionalTargetingAccuracy);
	RBActorWrapper GetClientTarget();
	void SetClientTarget(RBActorWrapper newClientTarget);
	RBActorWrapper GetTargeted();
	void SetTargeted(RBActorWrapper newTargeted);

	//AUTO-GENERATED FUNCTION PROXIES
	RBActorWrapper GetClientTarget2();
	void TargetChanged();
	void OnTargetChanged();
	bool TryActivate(RBActorWrapper TargetOverride);
	bool ValidateTargetTrace(RBActorWrapper InTarget);
	bool ValidateTarget2(RBActorWrapper InTarget);
	RBActorWrapper GetTarget2();
private:
	PIMPL
};