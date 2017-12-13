#pragma once

#include "../wrapperstructs.h"
#include "../actorwrapper.h"
#include "../carwrapper.h"

class BAKKESMOD_PLUGIN_IMPORT CarComponentWrapper : public ActorWrapper
{

public:
	CONSTRUCTORS(CarComponentWrapper)

	//AUTO GENERATED
	GETSETH(bool, AutoActivate)
	GETSETH(bool, Created)
	GETSETH(float, ActivityTime)


	CarWrapper GetCar();

	void SetActive(bool active);
	bool CanActivate();
	bool CanDeactivate();
	void RemoveFromCar();
	float GetInactiveTime();
	float GetActiveTime();
private:
	PIMPL
};