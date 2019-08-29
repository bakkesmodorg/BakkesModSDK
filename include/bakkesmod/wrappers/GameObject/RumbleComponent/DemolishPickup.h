#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT DemolishPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(DemolishPickup)

	//AUTO-GENERATED FROM FIELDS
	unsigned char GetDemolishTarget();
	void SetDemolishTarget(unsigned char newDemolishTarget);
	unsigned char GetDemolishSpeed();
	void SetDemolishSpeed(unsigned char newDemolishSpeed);
	unsigned char GetOldTarget();
	void SetOldTarget(unsigned char newOldTarget);
	unsigned char GetOldSpeed();
	void SetOldSpeed(unsigned char newOldSpeed);

	//AUTO-GENERATED FUNCTION PROXIES
	void PickupEnd();
	void PickupStart();
private:
	PIMPL
};