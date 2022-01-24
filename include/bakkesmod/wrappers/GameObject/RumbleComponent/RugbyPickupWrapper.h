#pragma once
#include "RumblePickupComponentWrapper.h"
class RBActorWrapper;
class BallWrapper;
class CarWrapper;


class BAKKESMOD_PLUGIN_IMPORT RugbyPickupWrapper : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(RugbyPickupWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetAttachTime();
	void SetAttachTime(float AttachTime);
	float GetMinDetachTime();
	void SetMinDetachTime(float MinDetachTime);
	float GetMinBreakTime();
	void SetMinBreakTime(float MinBreakTime);
	float GetMinBreakForce();
	void SetMinBreakForce(float MinBreakForce);
	float GetCheckLastTouchRate();
	void SetCheckLastTouchRate(float CheckLastTouchRate);
	float GetKickOffActivationDelay();
	void SetKickOffActivationDelay(float KickOffActivationDelay);
	BallWrapper GetWeldedBall();
	void SetWeldedBall(BallWrapper WeldedBall);
	float GetLastTouchCheckTime();
	void SetLastTouchCheckTime(float LastTouchCheckTime);
	unsigned int GetbBallWelded();
	void SetbBallWelded(unsigned int bBallWelded);
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	bool DisableBallImpactForces();
	void DeactivationFX();
	void HandleBallExploded(BallWrapper Ball);
	bool GetShouldHideActivateUI();
	void DoBreak();
	bool GetWasRecentlyAttached();
	void HandleCarTouch(BallWrapper InBall, CarWrapper InCar, unsigned char HitType);
	void HandleHitBall(CarWrapper InCar, BallWrapper InBall, Vector& HitLocation, Vector& HitNormal);
	void HandleBallWeldedChanged();
	void PickupTick(float DeltaTime);
	void RemovePickupFX();
	void PickupEnd();
	void InitPickupFX();
	void PickupStart();
	bool GetCanDetach();
	bool TryActivate(RBActorWrapper TargetOverride);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};