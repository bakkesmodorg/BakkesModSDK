#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/VehicleWrapper.h"
class RumblePickupComponentWrapper;
class RBActorWrapper;
class GameEventWrapper;
class ActorWrapper;
class WheelWrapper;
class FlipCarComponentWrapper;
class DoubleJumpComponentWrapper;
class BallWrapper;
class CarComponentWrapper;
class PriWrapper;
class PrimitiveComponentWrapper;

class BAKKESMOD_PLUGIN_IMPORT CarWrapper : public VehicleWrapper {
public:
	CONSTRUCTORS(CarWrapper)

	//BEGIN SELF IMPLEMENTED
	bool IsBoostCheap();
	void SetBoostCheap(bool b);
	void SetCarRotation(Rotator rotation);
	void ForceBoost(bool force);
	string GetOwnerName();
	void Unfreeze();
	ControllerInput GetInput();
	void SetInput(ControllerInput input);
	void Destroy();
	void Demolish();
	int GetLoadoutBody();	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	ArrayWrapper<CarComponentWrapper> GetDefaultCarComponents();
	DoubleJumpComponentWrapper GetDoubleJumpComponent();
	FlipCarComponentWrapper GetFlipComponent();
	unsigned char GetDemolishTarget();
	void SetDemolishTarget(unsigned char newDemolishTarget);
	unsigned char GetDemolishSpeed();
	void SetDemolishSpeed(unsigned char newDemolishSpeed);
	float GetMaxTimeForDodge();
	void SetMaxTimeForDodge(float newMaxTimeForDodge);
	float GetLastWheelsHitBallTime();
	void SetLastWheelsHitBallTime(float newLastWheelsHitBallTime);
	float GetReplicatedCarScale();
	void SetReplicatedCarScale(float newReplicatedCarScale);
	unsigned long GetbDemolishOnOpposingGround();
	void SetbDemolishOnOpposingGround(unsigned long newbDemolishOnOpposingGround);
	unsigned long GetbWasOnOpposingGround();
	void SetbWasOnOpposingGround(unsigned long newbWasOnOpposingGround);
	unsigned long GetbDemolishOnGoalZone();
	void SetbDemolishOnGoalZone(unsigned long newbDemolishOnGoalZone);
	unsigned long GetbWasInGoalZone();
	void SetbWasInGoalZone(unsigned long newbWasInGoalZone);
	unsigned long GetbJumped();
	void SetbJumped(unsigned long newbJumped);
	unsigned long GetbDoubleJumped();
	void SetbDoubleJumped(unsigned long newbDoubleJumped);
	unsigned long GetbOverrideHandbrakeOn();
	void SetbOverrideHandbrakeOn(unsigned long newbOverrideHandbrakeOn);
	unsigned long GetbOverrideBoostOn();
	void SetbOverrideBoostOn(unsigned long newbOverrideBoostOn);
	PriWrapper GetAttackerPRI();
	void SetAttackerPRI(PriWrapper newAttackerPRI);
	BallWrapper GetAttachedBall();
	void SetAttachedBall(BallWrapper newAttachedBall);
	Vector GetMouseAccel();
	void SetMouseAccel(Vector newMouseAccel);
	Vector GetMouseAirAccel();
	void SetMouseAirAccel(Vector newMouseAirAccel);
	RumblePickupComponentWrapper GetAttachedPickup();
	void SetAttachedPickup(RumblePickupComponentWrapper newAttachedPickup);
	Vector GetReplayFocusOffset();
	void SetReplayFocusOffset(Vector newReplayFocusOffset);
	float GetAddedBallForceMultiplier();
	void SetAddedBallForceMultiplier(float newAddedBallForceMultiplier);
	float GetAddedCarForceMultiplier();
	void SetAddedCarForceMultiplier(float newAddedCarForceMultiplier);
	GameEventWrapper GetGameEvent();
	void SetGameEvent(GameEventWrapper newGameEvent);

	//AUTO-GENERATED FUNCTION PROXIES
	float GetMaxDriveBackwardsSpeed();
	float GetMaxDriveForwardSpeed();
	Vector GetReplayFocusLocation();
	void OnPickupChanged(RumblePickupComponentWrapper inPickup);
	void SetAttachedPickup2(RumblePickupComponentWrapper inPickup);
	void EnablePodiumMode();
	void HasBall(BallWrapper InBall);
	void CopyPushFactorCurve();
	void ClearAttacker();
	void NotifyNewAttacker(PriWrapper Attacker);
	void UpdateTeamIndicator();
	void UpdateBallIndicator();
	void eventOnSuperSonicChanged();
	void eventOnGroundChanged();
	void DemolishDestroyTimer();
	void Demolish2(RBActorWrapper Demolisher);
	bool IsBumperHit_Extent(Vector& HitLocation);
	bool IsBumperHit_CarAngle(CarWrapper OtherCar);
	bool IsBumperHit_HitNormalAngle(Vector& HitNormal);
	bool IsBumperHit2(CarWrapper OtherCar, Vector& HitLocation, Vector& HitNormal);
	bool Teleport(Vector& SpawnLocation, Rotator& SpawnRotation, unsigned long bStopVelocity, unsigned long bUpdateRotation, float ExtraForce);
	void OnJumpReleased();
	void OnJumpPressed();
	void LaunchBall();
	void eventSetVehicleInput(ControllerInput& NewInput);
	bool CanDemolish(CarWrapper HitCar);
	bool ShouldDemolish(CarWrapper HitCar, Vector& HitLocation, Vector& HitNormal, unsigned char* Result);
	unsigned char ApplyCarImpactForces(CarWrapper OtherCar, Vector& HitLocation, Vector& HitNormal);
	void ApplyBallImpactForces(BallWrapper Ball, Vector& HitLocation);
	bool IsDodging();
	void OnHitBall(BallWrapper Ball, Vector& HitLocation, Vector& HitNormal);
	bool AnyWheelTouchingGround();
	CarComponentWrapper GiveCarComponent(CarComponentWrapper ComponentArchetype, PriWrapper Activator);
	void AddDefaultCarComponents();
	void DetachPrimitiveComponent(PrimitiveComponentWrapper Component);
	void HandleWheelBallHit(WheelWrapper Wheel);
	void RespawnInPlace();
	void SetCarScale(float NewScale);
	void OnClubColorsChanged();
	void OnTeamPaintChanged();
	void UpdateTeamLoadout();
	void InitTeamPaint();
	int GetLoadoutTeamIndex();
	int GetPreviewTeamIndex();
	bool HasTeam();
	void HandleLoadoutSelected(PriWrapper MyPRI);
	void HandleGameEventChanged(PriWrapper MyPRI);
	void OnPRIChanged();
	void OnControllerChanged();
private:
	PIMPL
};