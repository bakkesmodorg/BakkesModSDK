#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/TargetedPickup.h"
class FXActorWrapper;
class BallWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT BallFreezePickup : public TargetedPickup {
public:
	CONSTRUCTORS(BallFreezePickup)

	//AUTO-GENERATED FROM FIELDS
	FXActorWrapper GetFreezeBreakFXArchetype();
	void SetFreezeBreakFXArchetype(FXActorWrapper newFreezeBreakFXArchetype);
	FXActorWrapper GetFreezeFXArchetype();
	void SetFreezeFXArchetype(FXActorWrapper newFreezeFXArchetype);
	unsigned long GetbMaintainMomentum();
	void SetbMaintainMomentum(unsigned long newbMaintainMomentum);
	unsigned long GetbTouched();
	void SetbTouched(unsigned long newbTouched);
	float GetTimeToStop();
	void SetTimeToStop(float newTimeToStop);
	float GetStopMomentumPercentage();
	void SetStopMomentumPercentage(float newStopMomentumPercentage);
	BallWrapper GetBall();
	void SetBall(BallWrapper newBall);
	Vector GetOrigLinearVelocity();
	void SetOrigLinearVelocity(Vector newOrigLinearVelocity);
	Vector GetOrigAngularVelocity();
	void SetOrigAngularVelocity(Vector newOrigAngularVelocity);
	float GetOrigSpeed();
	void SetOrigSpeed(float newOrigSpeed);
	float GetRepOrigSpeed();
	void SetRepOrigSpeed(float newRepOrigSpeed);
	FXActorWrapper GetFreezeFX();
	void SetFreezeFX(FXActorWrapper newFreezeFX);

	//AUTO-GENERATED FUNCTION PROXIES
	void PickupEnd();
	void HandleBallExploded(BallWrapper InBall);
	void HandleBallHit(BallWrapper InBall, CarWrapper InCar, unsigned char HitType);
	void ApplyForces(float ActiveTime);
	void OnTargetChanged();
	void PickupStart();
private:
	PIMPL
};