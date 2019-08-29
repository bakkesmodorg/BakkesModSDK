#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/VehiclePickupWrapper.h"
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT BoostPickupWrapper : public VehiclePickupWrapper {
public:
	CONSTRUCTORS(BoostPickupWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetBoostAmount();
	void SetBoostAmount(float newBoostAmount);
	unsigned char GetBoostType();
	void SetBoostType(unsigned char newBoostType);

	//AUTO-GENERATED FUNCTION PROXIES
	void PlayPickedUpFX();
	void Pickup2(CarWrapper Car);
	bool CanPickup(CarWrapper Car);
private:
	PIMPL
};