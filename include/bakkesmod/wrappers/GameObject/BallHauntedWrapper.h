#pragma once
#include "BallWrapper.h"
class GoalWrapper;
class CarWrapper;


class BAKKESMOD_PLUGIN_IMPORT BallHauntedWrapper : public BallWrapper {
public:
	CONSTRUCTORS(BallHauntedWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetTrappedHoverHeight();
	void SetTrappedHoverHeight(float TrappedHoverHeight);
	float GetHorizontalSpeed();
	void SetHorizontalSpeed(float HorizontalSpeed);
	float GetVerticalSpeed();
	void SetVerticalSpeed(float VerticalSpeed);
	float GetArrivalDistance();
	void SetArrivalDistance(float ArrivalDistance);
	float GetTrappedHorizontalSpeed();
	void SetTrappedHorizontalSpeed(float TrappedHorizontalSpeed);
	float GetTrappedVerticalSpeed();
	void SetTrappedVerticalSpeed(float TrappedVerticalSpeed);
	float GetTrappedCaptureTime();
	void SetTrappedCaptureTime(float TrappedCaptureTime);
	float GetHitPhysicsDuration();
	void SetHitPhysicsDuration(float HitPhysicsDuration);
	unsigned char GetReplicatedBeamBrokenValue();
	void SetReplicatedBeamBrokenValue(unsigned char ReplicatedBeamBrokenValue);
	unsigned char GetLastTeamTouch();
	void SetLastTeamTouch(unsigned char LastTeamTouch);
	unsigned char GetDeactivatedGoalIndex();
	void SetDeactivatedGoalIndex(unsigned char DeactivatedGoalIndex);
	unsigned char GetTotalActiveBeams();
	void SetTotalActiveBeams(unsigned char TotalActiveBeams);
	Vector GetSeekTarget();
	void SetSeekTarget(Vector SeekTarget);
	float GetNextNeutralTime();
	void SetNextNeutralTime(float NextNeutralTime);
	unsigned int GetbHitPhysicsActive();
	void SetbHitPhysicsActive(unsigned int bHitPhysicsActive);
	unsigned int GetbIsBallBeamed();
	void SetbIsBallBeamed(unsigned int bIsBallBeamed);
	unsigned int GetbIsTrapped();
	void SetbIsTrapped(unsigned int bIsTrapped);
	float GetCurrentCaptureTime();
	void SetCurrentCaptureTime(float CurrentCaptureTime);
	float GetCaptureTimePercentage();
	void SetCaptureTimePercentage(float CaptureTimePercentage);
	float GetCaptureTimeAtExit();
	void SetCaptureTimeAtExit(float CaptureTimeAtExit);
	GoalWrapper GetActiveGoal();
	void SetActiveGoal(GoalWrapper ActiveGoal);
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	Vector GetBallDestination();
	float GetVerticalVelocity(Vector& Destination);
	Vector GetDesiredVelocity();
	void AddHauntedForces();
	void ScoreTrapGoal();
	void SetLastTeamTouch2(unsigned char InLastTeamTouch);
	void SetBallIsTrapped(unsigned int bValue, GoalWrapper Goal);
	void SetBallHitData(CarWrapper HitCar, Vector& HitLocation, Vector& HitNormal, unsigned char HitType);
	void TryBreakBeam(CarWrapper HitCar);
	void OnCarTouch(CarWrapper HitCar, unsigned char HitType);
	void ActivateHitPhysics();
	void SetBallPhased(unsigned int bValue, unsigned int TeamIndex);
	void SetBallTarget();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};