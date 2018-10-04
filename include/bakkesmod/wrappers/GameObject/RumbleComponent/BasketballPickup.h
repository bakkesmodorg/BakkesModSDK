#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class CarWrapper;
class RBActorWrapper;
class BallWrapper;

class BAKKESMOD_PLUGIN_IMPORT BasketballPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(BasketballPickup)

	//AUTO-GENERATED FROM FIELDS
	Vector GetBallOffset();
	void SetBallOffset(Vector newBallOffset);
	float GetAttachedBallMass();
	void SetAttachedBallMass(float newAttachedBallMass);
	Vector GetLaunchForce();
	void SetLaunchForce(Vector newLaunchForce);
	BallWrapper GetWeldedBall();
	void SetWeldedBall(BallWrapper newWeldedBall);
	float GetOldBallMass();
	void SetOldBallMass(float newOldBallMass);

	//AUTO-GENERATED FUNCTION PROXIES
	void HandleCarTouch(BallWrapper InBall, CarWrapper InCar, unsigned char HitType);
	void PickupStart();
	void HandleHitBall(CarWrapper InCar, BallWrapper InBall);
	bool TryActivate(RBActorWrapper TargetOverride);
	void OnCreated();
private:
	PIMPL
};