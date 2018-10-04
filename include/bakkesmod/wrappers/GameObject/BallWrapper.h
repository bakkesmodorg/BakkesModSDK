#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/RBActorWrapper.h"
class GoalWrapper;
class PriWrapper;
class ServerWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT BallWrapper : public RBActorWrapper {
public:
	CONSTRUCTORS(BallWrapper)

	//BEGIN SELF IMPLEMENTED
	float GetLastTouchTime();
	PredictionInfo PredictPosition(float timeAhead);	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbAllowPlayerExplosionOverride();
	void SetbAllowPlayerExplosionOverride(unsigned long newbAllowPlayerExplosionOverride);
	unsigned long GetbNotifyGroundHit();
	void SetbNotifyGroundHit(unsigned long newbNotifyGroundHit);
	unsigned long GetbEndOfGameHidden();
	void SetbEndOfGameHidden(unsigned long newbEndOfGameHidden);
	unsigned long GetbFadeIn();
	void SetbFadeIn(unsigned long newbFadeIn);
	unsigned long GetbFadeOut();
	void SetbFadeOut(unsigned long newbFadeOut);
	unsigned long GetbPredictionOnGround();
	void SetbPredictionOnGround(unsigned long newbPredictionOnGround);
	unsigned long GetbCanBeAttached();
	void SetbCanBeAttached(unsigned long newbCanBeAttached);
	unsigned long GetbBallDemolish();
	void SetbBallDemolish(unsigned long newbBallDemolish);
	unsigned long GetbNewFalling();
	void SetbNewFalling(unsigned long newbNewFalling);
	unsigned long GetbItemFreeze();
	void SetbItemFreeze(unsigned long newbItemFreeze);
	float GetRadius();
	void SetRadius(float newRadius);
	float GetVisualRadius();
	void SetVisualRadius(float newVisualRadius);
	float GetLastCalculateCarHit();
	Vector GetInitialLocation();
	void SetInitialLocation(Vector newInitialLocation);
	void SetInitialRotation(Rotator newInitialRotation);
	float GetLastHitWorldTime();
	float GetReplicatedBallScale();
	void SetReplicatedBallScale(float newReplicatedBallScale);
	float GetReplicatedWorldBounceScale();
	void SetReplicatedWorldBounceScale(float newReplicatedWorldBounceScale);
	float GetReplicatedBallGravityScale();
	void SetReplicatedBallGravityScale(float newReplicatedBallGravityScale);
	float GetReplicatedBallMaxLinearSpeedScale();
	void SetReplicatedBallMaxLinearSpeedScale(float newReplicatedBallMaxLinearSpeedScale);
	float GetReplicatedAddedCarBounceScale();
	void SetReplicatedAddedCarBounceScale(float newReplicatedAddedCarBounceScale);
	float GetAdditionalCarGroundBounceScaleZ();
	void SetAdditionalCarGroundBounceScaleZ(float newAdditionalCarGroundBounceScaleZ);
	float GetAdditionalCarGroundBounceScaleXY();
	void SetAdditionalCarGroundBounceScaleXY(float newAdditionalCarGroundBounceScaleXY);
	unsigned char GetHitTeamNum();
	void SetHitTeamNum(unsigned char newHitTeamNum);
	ServerWrapper GetGameEvent();
	float GetExplosionTime();
	void SetExplosionTime(float newExplosionTime);
	Vector GetOldLocation();
	void SetOldLocation(Vector newOldLocation);
	float GetPredictionTimestep();
	void SetPredictionTimestep(float newPredictionTimestep);
	float GetLastPredictionTime();
	void SetLastPredictionTime(float newLastPredictionTime);
	float GetBallSloMoRadius();
	void SetBallSloMoRadius(float newBallSloMoRadius);
	float GetBallSloMoDuration();
	void SetBallSloMoDuration(float newBallSloMoDuration);
	float GetBallSloMoDilation();
	void SetBallSloMoDilation(float newBallSloMoDilation);
	float GetBallSloMoCooldown();
	void SetBallSloMoCooldown(float newBallSloMoCooldown);
	float GetBallSloMoNext();
	void SetBallSloMoNext(float newBallSloMoNext);
	float GetBallSloMoDiffSpeed();
	void SetBallSloMoDiffSpeed(float newBallSloMoDiffSpeed);
	int GetBallTouchScore();
	void SetBallTouchScore(int newBallTouchScore);
	float GetGroundForce();
	void SetGroundForce(float newGroundForce);
	CarWrapper GetCurrentAffector();
	void SetCurrentAffector(CarWrapper newCurrentAffector);

	//AUTO-GENERATED FUNCTION PROXIES
	Vector GetTrajectoryStartVelocity();
	Rotator GetTrajectoryStartRotation();
	Vector GetTrajectoryStartLocation();
	bool ShouldDrawTrajectory();
	float GetAdditionalCarBounceScaleZ(CarWrapper Car);
	void SetTouchScoreValue(int NewValue);
	void SetEndOfGameHidden();
	void Explode(GoalWrapper ExplosionGoal, Vector& ExplodeLocation, PriWrapper Scorer);
	bool ShouldDemolish(CarWrapper Car);
	void DoDestroy();
	void DoExplode();
	void RestoreTimeDilation();
	void GetBallTimeDilation();
	void Launch(Vector& LaunchPosition, Vector& LaunchDirection);
	void OnCarTouch(CarWrapper HitCar, unsigned char HitType);
	void RecordCarHit(CarWrapper HitCar, Vector& HitLocation, Vector& HitNormal, unsigned char HitType);
	bool IsGroundHit(Vector& HitNormal);
	bool IsRoundActive();
	void eventOnHitGoal(GoalWrapper Goal, Vector& HitLoc);
	void TurnOff();
	void SetBallSloMoDiffSpeed2(float InDiffSpeed);
	void SetBallSloMoRadius2(float Inradius);
	void SetBallSloMoCooldown2(float InCooldown);
	void SetBallSloMoDilation2(float InDilation);
	void SetBallSloMoDuration2(float InDuration);
	void SetWorldBounceScale(float NewScale);
	void SetCarBounceScale(float NewScale);
	void SetBallMaxLinearSpeedScale(float InMaxLinearSpeedScale);
	void SetBallGravityScale(float InBallGravityScale);
	void SetBallScale(float NewScale);
	void EventHitGoal(BallWrapper Ball, GoalWrapper Goal);
private:
	PIMPL
};