#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/VehicleWrapper.h"
class WheelWrapper;
class PriXWrapper;
class GameEventWrapper;
class RumblePickupComponentWrapper;
class ActorWrapper;
class RBActorWrapper;
class PriWrapper;
class FXActorWrapper;
class CarComponentWrapper;
class FlipCarComponentWrapper;
class BallWrapper;
class PrimitiveComponentWrapper;

class BAKKESMOD_PLUGIN_IMPORT CarWrapper : public VehicleWrapper {
public:
	CONSTRUCTORS(CarWrapper)

	//BEGIN SELF IMPLEMENTED
	bool IsBoostCheap();
	void SetBoostCheap(bool b);
	void SetCarRotation(Rotator rotation);
	void ForceBoost(bool force);
    std::string GetOwnerName();
	void Unfreeze();
	ControllerInput GetInput();
	void SetInput(ControllerInput input);
	void Destroy();
	void Demolish();
	unsigned long HasFlip();
	int GetLoadoutBody();	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	//Only works in freeplay
	void SetCarColor(LinearColor mainColor, LinearColor secondaryColor);

	ArrayWrapper<CarComponentWrapper> GetDefaultCarComponents();
	FlipCarComponentWrapper GetFlipComponent();
	unsigned char GetDemolishTarget();
	void SetDemolishTarget(unsigned char newDemolishTarget);
	unsigned char GetDemolishSpeed();
	void SetDemolishSpeed(unsigned char newDemolishSpeed);
	unsigned long GetbLoadoutSet();
	void SetbLoadoutSet(unsigned long newbLoadoutSet);
	unsigned long GetbDemolishOnOpposingGround();
	void SetbDemolishOnOpposingGround(unsigned long newbDemolishOnOpposingGround);
	unsigned long GetbWasOnOpposingGround();
	void SetbWasOnOpposingGround(unsigned long newbWasOnOpposingGround);
	unsigned long GetbDemolishOnGoalZone();
	void SetbDemolishOnGoalZone(unsigned long newbDemolishOnGoalZone);
	unsigned long GetbWasInGoalZone();
	void SetbWasInGoalZone(unsigned long newbWasInGoalZone);
	unsigned long GetbOverrideHandbrakeOn();
	void SetbOverrideHandbrakeOn(unsigned long newbOverrideHandbrakeOn);
	unsigned long GetbCollidesWithVehicles();
	void SetbCollidesWithVehicles(unsigned long newbCollidesWithVehicles);
	unsigned long GetbOverrideBoostOn();
	void SetbOverrideBoostOn(unsigned long newbOverrideBoostOn);
	FXActorWrapper GetExitFXArchetype();
	void SetExitFXArchetype(FXActorWrapper newExitFXArchetype);
	float GetMaxTimeForDodge();
	void SetMaxTimeForDodge(float newMaxTimeForDodge);
	float GetLastWheelsHitBallTime();
	void SetLastWheelsHitBallTime(float newLastWheelsHitBallTime);
	float GetReplicatedCarScale();
	void SetReplicatedCarScale(float newReplicatedCarScale);
	FXActorWrapper GetBodyFXActor();
	void SetBodyFXActor(FXActorWrapper newBodyFXActor);
	PriWrapper GetAttackerPRI();
	void SetAttackerPRI(PriWrapper newAttackerPRI);
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
	void OnPickupChanged(RumblePickupComponentWrapper InPickup);
	void SetAttachedPickup2(RumblePickupComponentWrapper InPickup);
	void EnablePodiumMode();
	void CopyPushFactorCurve();
	void ClearAttacker();
	void NotifyNewAttacker(PriWrapper Attacker);
	void UpdateBallIndicator();
	void eventOnSuperSonicChanged();
	void eventOnGroundChanged();
	void FellOutOfWorld();
	void DemolishDestroyTimer();
	void Demolish2(RBActorWrapper Demolisher);
	bool Teleport(Vector& SpawnLocation, Rotator& SpawnRotation, unsigned long bStopVelocity, unsigned long bUpdateRotation, float ExtraForce);
	void OnJumpReleased();
	void OnJumpPressed();
	void eventSetVehicleInput(ControllerInput& NewInput);
	bool CanDemolish(CarWrapper HitCar);
	bool ShouldDemolish(CarWrapper HitCar, Vector& HitLocation, Vector& HitNormal, unsigned char* Result);
	unsigned char ApplyCarImpactForces(CarWrapper OtherCar, Vector& HitLocation, Vector& HitNormal);
	bool IsBumperHit(CarWrapper OtherCar);
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
	void HandleTeamChanged(PriXWrapper MyPRI);
	bool UpdateTeamLoadout();
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