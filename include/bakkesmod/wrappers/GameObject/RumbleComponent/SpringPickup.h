#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/TargetedPickup.h"
class BallWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT SpringPickup : public TargetedPickup {
public:
	CONSTRUCTORS(SpringPickup)

	//AUTO-GENERATED FROM FIELDS
	float GetForce();
	void SetForce(float newForce);
	float GetVerticalForce();
	void SetVerticalForce(float newVerticalForce);
	Vector GetTorque();
	void SetTorque(Vector newTorque);
	unsigned long GetbApplyRelativeForce();
	void SetbApplyRelativeForce(unsigned long newbApplyRelativeForce);
	unsigned long GetbApplyConstantForce();
	void SetbApplyConstantForce(unsigned long newbApplyConstantForce);
	unsigned long GetbBreakConstantForceWithHit();
	void SetbBreakConstantForceWithHit(unsigned long newbBreakConstantForceWithHit);
	unsigned long GetbApplyRelativeConstantForce();
	void SetbApplyRelativeConstantForce(unsigned long newbApplyRelativeConstantForce);
	unsigned long GetbInstant();
	void SetbInstant(unsigned long newbInstant);
	unsigned long GetbFollowAfterHit();
	void SetbFollowAfterHit(unsigned long newbFollowAfterHit);
	unsigned long GetbSpringed();
	void SetbSpringed(unsigned long newbSpringed);
	float GetRelativeForceNormalDirection();
	void SetRelativeForceNormalDirection(float newRelativeForceNormalDirection);
	float GetMaxSpringLength();
	void SetMaxSpringLength(float newMaxSpringLength);
	float GetConstantForce();
	void SetConstantForce(float newConstantForce);
	Vector GetFromOffset();
	void SetFromOffset(Vector newFromOffset);
	Vector GetSpringMeshScale();
	void SetSpringMeshScale(Vector newSpringMeshScale);
	float GetSpringMeshInitialSize();
	void SetSpringMeshInitialSize(float newSpringMeshInitialSize);
	Rotator GetSpringRotationOffset();
	void SetSpringRotationOffset(Rotator newSpringRotationOffset);
	Vector GetHittingMeshScale();
	void SetHittingMeshScale(Vector newHittingMeshScale);
	Vector GetHittingMeshOffset();
	void SetHittingMeshOffset(Vector newHittingMeshOffset);
	Rotator GetHittingRotationOffset();
	void SetHittingRotationOffset(Rotator newHittingRotationOffset);
	float GetHitDistanceOffset();
	void SetHitDistanceOffset(float newHitDistanceOffset);
	float GetAfterSpringDuration();
	void SetAfterSpringDuration(float newAfterSpringDuration);
	unsigned char GetBallHitType();
	void SetBallHitType(unsigned char newBallHitType);
	float GetMinSpringLength();
	void SetMinSpringLength(float newMinSpringLength);
	float GetWeldedForceScalar();
	void SetWeldedForceScalar(float newWeldedForceScalar);
	float GetWeldedVerticalForce();
	void SetWeldedVerticalForce(float newWeldedVerticalForce);
	float GetCurrentSpringLength();
	void SetCurrentSpringLength(float newCurrentSpringLength);
	float GetSpringedTime();
	void SetSpringedTime(float newSpringedTime);
	float GetAfterSpringTime();
	void SetAfterSpringTime(float newAfterSpringTime);
	float GetSpringToTime();
	void SetSpringToTime(float newSpringToTime);
	Vector GetSpringOrigin();
	void SetSpringOrigin(Vector newSpringOrigin);
	Vector GetSpringedLocation();
	void SetSpringedLocation(Vector newSpringedLocation);
	Vector GetSpringedNormal();
	void SetSpringedNormal(Vector newSpringedNormal);
	float GetSpringedLength();
	void SetSpringedLength(float newSpringedLength);

	//AUTO-GENERATED FUNCTION PROXIES
	void PickupEnd();
	void HandleCarTouchedBall(BallWrapper Ball, CarWrapper OtherCar, unsigned char HitType);
	void ScaleSpringMeshToLocation(Vector& NewLocation, Vector& TargetLoction);
	void ApplyForces(float ActiveTime);
	Vector GetRelativeConstantForce(Vector& Direction);
	Vector GetRelativeImpulse(Vector& Direction);
	void DoSpring(unsigned long bFirstHit);
	void PickupStart();
private:
	PIMPL
};