#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/TargetedPickup.h"
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT SwapperPickup : public TargetedPickup {
public:
	CONSTRUCTORS(SwapperPickup)

	//AUTO-GENERATED FROM FIELDS
	CarWrapper GetOtherCar();
	void SetOtherCar(CarWrapper newOtherCar);

	//AUTO-GENERATED FUNCTION PROXIES
	void PickupEnd();
	void OnTargetChanged();
	void PickupStart();
private:
	PIMPL
};