#pragma once
#include "wrapperstructs.h"
#include "actorwrapper.h"
class BAKKESMOD_PLUGIN_IMPORT BoostWrapper : public ActorWrapper
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
	GETSETH(bool, OnlyApplyRechargeToMyHalf)
	GETSETH(bool, OnlyApplyRechargeToOpposingHalf)
	GETSETH(bool, DemolishOnEmptyMyHalf)
	GETSETH(bool, DemolishOnEmptyOpposingHalf)
	GETSETH(bool, CachedOnMyHalf)

	float GetCurrentBoostAmount();
	bool GetIsUnlimitedBoost();

	//SELF IMPLEMENTED
	void SetBoostAmount(float amount);
	void AddBoostAmount(float amount);
	void SetIsUnlimitedBoost(bool unlimited);
private:
	PIMPL
};

