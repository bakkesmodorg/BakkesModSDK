#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/TargetedPickup.h"
class BallWrapper;
class RBActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT GrapplingHookPickup : public TargetedPickup {
public:
	CONSTRUCTORS(GrapplingHookPickup)

	//AUTO-GENERATED FROM FIELDS
	float GetImpulse();
	void SetImpulse(float newImpulse);
	float GetForce();
	void SetForce(float newForce);
	float GetMaxRopeLength();
	void SetMaxRopeLength(float newMaxRopeLength);
	float GetPredictionSpeed();
	void SetPredictionSpeed(float newPredictionSpeed);
	unsigned long GetbDeactivateOnTouch();
	void SetbDeactivateOnTouch(unsigned long newbDeactivateOnTouch);
	unsigned long GetbInstant();
	void SetbInstant(unsigned long newbInstant);
	unsigned long GetbBlocked();
	void SetbBlocked(unsigned long newbBlocked);
	unsigned long GetbAttachedToBall();
	void SetbAttachedToBall(unsigned long newbAttachedToBall);
	Vector GetRopeMeshScale();
	void SetRopeMeshScale(Vector newRopeMeshScale);
	float GetRopeMeshInitialSize();
	void SetRopeMeshInitialSize(float newRopeMeshInitialSize);
	Rotator GetRopeRotationOffset();
	void SetRopeRotationOffset(Rotator newRopeRotationOffset);
	Vector GetHookMeshScale();
	void SetHookMeshScale(Vector newHookMeshScale);
	Vector GetHookMeshOffset();
	void SetHookMeshOffset(Vector newHookMeshOffset);
	Rotator GetHookRotationOffset();
	void SetHookRotationOffset(Rotator newHookRotationOffset);
	float GetHitDistanceOffset();
	void SetHitDistanceOffset(float newHitDistanceOffset);
	float GetAfterAttachDuration();
	void SetAfterAttachDuration(float newAfterAttachDuration);
	float GetBlockedRequiredMoveDistance();
	void SetBlockedRequiredMoveDistance(float newBlockedRequiredMoveDistance);
	float GetBlockedRequiredMoveTime();
	void SetBlockedRequiredMoveTime(float newBlockedRequiredMoveTime);
	float GetBlockedStartTime();
	void SetBlockedStartTime(float newBlockedStartTime);
	Vector GetBlockedStartPos();
	void SetBlockedStartPos(Vector newBlockedStartPos);
	BallWrapper GetBall();
	void SetBall(BallWrapper newBall);
	Vector GetRopeOrigin();
	void SetRopeOrigin(Vector newRopeOrigin);
	float GetRopeToTime();
	void SetRopeToTime(float newRopeToTime);
	float GetCurrentRopeLength();
	void SetCurrentRopeLength(float newCurrentRopeLength);
	float GetAttachTime();
	void SetAttachTime(float newAttachTime);

	//AUTO-GENERATED FUNCTION PROXIES
	void HandleBallExploded(BallWrapper InBall);
	void PickupEnd();
	void ScaleMeshToLocation(Vector& NewLocation, Vector& TargetLocation);
	Vector GetPredictedBallLocation(BallWrapper InBall);
	Vector GetTargetedLocation();
	void UpdateVisual(float DeltaTime);
	void PickupTick(float DeltaTime);
	void ApplyForces(float ActiveTime);
	void DoAttach();
	void PickupStart();
private:
	PIMPL
};