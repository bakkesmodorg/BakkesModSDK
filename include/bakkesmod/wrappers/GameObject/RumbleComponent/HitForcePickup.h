#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class RBActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT HitForcePickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(HitForcePickup)

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbBallForce();
	void SetbBallForce(unsigned long newbBallForce);
	unsigned long GetbCarForce();
	void SetbCarForce(unsigned long newbCarForce);
	unsigned long GetbDemolishCars();
	void SetbDemolishCars(unsigned long newbDemolishCars);
	float GetBallHitForce();
	void SetBallHitForce(float newBallHitForce);
	float GetCarHitForce();
	void SetCarHitForce(float newCarHitForce);
	float GetMinFXTime();
	void SetMinFXTime(float newMinFXTime);
	float GetOrigBallHitForce();
	void SetOrigBallHitForce(float newOrigBallHitForce);
	float GetOrigCarHitForce();
	void SetOrigCarHitForce(float newOrigCarHitForce);
	float GetLastFXTime();
	void SetLastFXTime(float newLastFXTime);

	//AUTO-GENERATED FUNCTION PROXIES
	void PickupEnd();
	void PickupStart();
private:
	PIMPL
};