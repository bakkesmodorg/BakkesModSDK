#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class BallWrapper;
class CarWrapper;
class RBActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT VelcroPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(VelcroPickup)

	//AUTO-GENERATED FROM FIELDS
	Vector GetBallOffset();
	void SetBallOffset(Vector newBallOffset);
	unsigned long GetbUseRealOffset();
	void SetbUseRealOffset(unsigned long newbUseRealOffset);
	unsigned long GetbHit();
	void SetbHit(unsigned long newbHit);
	unsigned long GetbBroken();
	void SetbBroken(unsigned long newbBroken);
	float GetAfterHitDuration();
	void SetAfterHitDuration(float newAfterHitDuration);
	float GetPostBreakDuration();
	void SetPostBreakDuration(float newPostBreakDuration);
	float GetMinBreakForce();
	void SetMinBreakForce(float newMinBreakForce);
	float GetMinBreakTime();
	void SetMinBreakTime(float newMinBreakTime);
	float GetCheckLastTouchRate();
	void SetCheckLastTouchRate(float newCheckLastTouchRate);
	BallWrapper GetWeldedBall();
	void SetWeldedBall(BallWrapper newWeldedBall);
	float GetOldBallMass();
	void SetOldBallMass(float newOldBallMass);
	float GetAttachTime();
	void SetAttachTime(float newAttachTime);
	float GetLastTouchCheckTime();
	void SetLastTouchCheckTime(float newLastTouchCheckTime);
	float GetBreakTime();
	void SetBreakTime(float newBreakTime);

	//AUTO-GENERATED FUNCTION PROXIES
	void DoBreak();
	void HandleCarTouch(BallWrapper InBall, CarWrapper InCar, unsigned char HitType);
	void PickupEnd();
	void OnBallHit();
	void PickupStart();
private:
	PIMPL
};