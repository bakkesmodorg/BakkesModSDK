#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class BallWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT GravityPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(GravityPickup)

	//AUTO-GENERATED FROM FIELDS
	float GetBallGravity();
	void SetBallGravity(float newBallGravity);
	float GetRange();
	void SetRange(float newRange);
	Vector GetOffset();
	void SetOffset(Vector newOffset);
	unsigned long GetbDeactivateOnTouch();
	void SetbDeactivateOnTouch(unsigned long newbDeactivateOnTouch);
	float GetRecordBallHitRate();
	void SetRecordBallHitRate(float newRecordBallHitRate);
	float GetLastRecordedBallHitTime();
	void SetLastRecordedBallHitTime(float newLastRecordedBallHitTime);
	BallWrapper GetPrevBall();
	void SetPrevBall(BallWrapper newPrevBall);

	//AUTO-GENERATED FUNCTION PROXIES
	void UpdateVisual();
	void ApplyForces(float ActiveTime);
	void PickupEnd();
	void PickupStart();
private:
	PIMPL
};