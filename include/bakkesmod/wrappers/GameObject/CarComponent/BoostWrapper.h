#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/CarComponent/CarComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT BoostWrapper : public CarComponentWrapper {
public:
	CONSTRUCTORS(BoostWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	float GetBoostConsumptionRate();
	void SetBoostConsumptionRate(float newBoostConsumptionRate);
	float GetMaxBoostAmount();
	void SetMaxBoostAmount(float newMaxBoostAmount);
	float GetStartBoostAmount();
	void SetStartBoostAmount(float newStartBoostAmount);
	float GetCurrentBoostAmount();
	void SetCurrentBoostAmount(float newCurrentBoostAmount);
	float GetBoostModifier();
	void SetBoostModifier(float newBoostModifier);
	float GetLastBoostAmountRequestTime();
	void SetLastBoostAmountRequestTime(float newLastBoostAmountRequestTime);
	float GetLastBoostAmount();
	void SetLastBoostAmount(float newLastBoostAmount);
	unsigned long GetbPendingConfirmBoostAmount();
	void SetbPendingConfirmBoostAmount(unsigned long newbPendingConfirmBoostAmount);
	unsigned long GetbNoBoost();
	void SetbNoBoost(unsigned long newbNoBoost);
	float GetBoostForce();
	void SetBoostForce(float newBoostForce);
	float GetMinBoostTime();
	void SetMinBoostTime(float newMinBoostTime);
	float GetRechargeRate();
	void SetRechargeRate(float newRechargeRate);
	float GetRechargeDelay();
	void SetRechargeDelay(float newRechargeDelay);
	int GetUnlimitedBoostRefCount();
	void SetUnlimitedBoostRefCount(int newUnlimitedBoostRefCount);
	unsigned char GetReplicatedBoostAmount();
	void SetReplicatedBoostAmount(unsigned char newReplicatedBoostAmount);

	//AUTO-GENERATED FUNCTION PROXIES
	bool ShouldPredictBoostConsumption();
	void ReadReplicatedBoostAmount();
	void eventSetReplicatedBoostAmount();
	void ApplyForces(float ActiveTime);
	void ClientGiveBoost(float Amount);
	void ConfirmBoostAmount2();
	void SendConfirmBoostAmount();
	void ClientFixBoostAmount(float TimeStamp, float Amount);
	void ServerConfirmBoostAmount(float TimeStamp, float Amount);
	void SetRechargeDelay2(float InRechargeDelay);
	void SetRechargeRate2(float InRechargeRate);
	void SetNoBoost(unsigned long Enabled);
	void SetUnlimitedBoost2(unsigned long Enabled);
	void SetUnlimitedBoostDelayed(unsigned long Enabled);
	void SetBoostModifier2(float Modifier);
	void SetBoostAmount(float Amount);
	void GiveBoost2(float Amount);
	void GiveStartingBoost();
	void GiveFullBoost();
	float GetPercentBoostFull();
	bool IsFull();
	void RemoveFromCar();
	bool CanDeactivate();
	bool CanActivate();
private:
	PIMPL
};