#pragma once
#include "../wrapperstructs.h"
#include "../actorwrapper.h"

#include "carcomponentwrapper.h"
class BAKKESMOD_PLUGIN_IMPORT BoostWrapper : public CarComponentWrapper
{

public:
	CONSTRUCTORS(BoostWrapper)

	//AUTO GENERATED
	GETSETH(float, MaxBoostAmount)
	GETSETH(float, StartBoostAmount)
	GETSETH(bool, IsActive)
	GETSETH(float, BoostConsumptionRate)
	GETSETH(float, BoostForce)
	GETSETH(float, MinBoostTime)
	GETSETH(float, RechargeRate)
	GETSETH(float, RechargeDelay)
	//GETSETH(bool, OnlyApplyRechargeToMyHalf) //These methods are removed as of RL 1.39
	//GETSETH(bool, OnlyApplyRechargeToOpposingHalf)
	//GETSETH(bool, DemolishOnEmptyMyHalf)
	//GETSETH(bool, DemolishOnEmptyOpposingHalf)
	//GETSETH(bool, CachedOnMyHalf)

	float GetCurrentBoostAmount();
	bool GetIsUnlimitedBoost();

	//SELF IMPLEMENTED
	void SetBoostAmount(float amount);
	void AddBoostAmount(float amount);
	void SetIsUnlimitedBoost(bool unlimited);
private:
	PIMPL
};

