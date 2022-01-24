#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class BallWrapper;
class RBActorWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT BasketballPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(BasketballPickup)

private:
	PIMPL
};