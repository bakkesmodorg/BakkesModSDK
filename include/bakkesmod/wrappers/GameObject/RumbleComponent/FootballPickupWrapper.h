#pragma once
#include "RumblePickupComponentWrapper.h"
class BallWrapper;
class CarWrapper;


class BAKKESMOD_PLUGIN_IMPORT FootballPickupWrapper : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(FootballPickupWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetAttachTime();
	void SetAttachTime(float AttachTime);
	float GetDetachTime();
	void SetDetachTime(float DetachTime);
	Vector GetAttachOffset();
	void SetAttachOffset(Vector AttachOffset);
	float GetCarFumbleForce();
	void SetCarFumbleForce(float CarFumbleForce);
	float GetDoubleJumpUpForce();
	void SetDoubleJumpUpForce(float DoubleJumpUpForce);
	float GetDemolishUpForce();
	void SetDemolishUpForce(float DemolishUpForce);
	float GetMinBreakTime();
	void SetMinBreakTime(float MinBreakTime);
	float GetMinAttachTime();
	void SetMinAttachTime(float MinAttachTime);
	float GetCheckLastTouchRate();
	void SetCheckLastTouchRate(float CheckLastTouchRate);
	float GetOutOfBoundsZ();
	void SetOutOfBoundsZ(float OutOfBoundsZ);
	BallWrapper GetWeldedBall();
	void SetWeldedBall(BallWrapper WeldedBall);
	float GetLastTouchCheckTime();
	void SetLastTouchCheckTime(float LastTouchCheckTime);
	BallWrapper GetPendingBall();
	void SetPendingBall(BallWrapper PendingBall);
	Vector GetPendingBallDodge();
	void SetPendingBallDodge(Vector PendingBallDodge);
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	bool IsDrivingOutOfBounds();
	bool DisableBallImpactForces();
	void DeactivationFX();
	void HandleBallExplode(BallWrapper Ball);
	bool GetShouldHideActivateUI();
	bool GetWasRecentlyAttached();
	void HandleCarTouch(BallWrapper InBall, CarWrapper InCar, unsigned char HitType);
	void FumbleBall(float UpwardForce);
	void ThrowPendingBall();
	void HandleHitBall(CarWrapper InCar, BallWrapper InBall, Vector& HitLocation, Vector& HitNormal);
	void OnWeldedBallChanged();
	void PickupTick(float DeltaTime);
	void PickupEnd();
	void PickupStart();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};