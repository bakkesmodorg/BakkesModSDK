#pragma once
#include "BallWrapper.h"
class CarWrapper;

struct AppliedBreakoutDamage
{
	unsigned char Id;
	Vector Location;
	int DamageIndex;
	int TotalDamage;
};



class BAKKESMOD_PLUGIN_IMPORT BallBreakoutWrapper : public BallWrapper {
public:
	CONSTRUCTORS(BallBreakoutWrapper)

	//BEGIN SELF IMPLEMENTED
	AppliedBreakoutDamage GetAppliedBreakoutDamage() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	unsigned int GetbClearTeamOnDamage();
	void SetbClearTeamOnDamage(unsigned int bClearTeamOnDamage);
	unsigned int GetbCanDamageOwnTeam();
	void SetbCanDamageOwnTeam(unsigned int bCanDamageOwnTeam);
	float GetMinDamageVelocity();
	void SetMinDamageVelocity(float MinDamageVelocity);
	float GetMinDamageTime();
	void SetMinDamageTime(float MinDamageTime);
	unsigned int GetMinImpactSpeedForCharge();
	void SetMinImpactSpeedForCharge(unsigned int MinImpactSpeedForCharge);
	float GetDoubleTapTime();
	void SetDoubleTapTime(float DoubleTapTime);
	float GetForceAccumDecayPerSecond();
	void SetForceAccumDecayPerSecond(float ForceAccumDecayPerSecond);
	float GetForceAccumMax();
	void SetForceAccumMax(float ForceAccumMax);
	float GetForceAccumRecent();
	void SetForceAccumRecent(float ForceAccumRecent);
	unsigned char GetLastTeamTouch();
	void SetLastTeamTouch(unsigned char LastTeamTouch);
	CarWrapper GetLastCarTouch();
	void SetLastCarTouch(CarWrapper LastCarTouch);
	unsigned int GetLastDamage();
	void SetLastDamage(unsigned int LastDamage);
	float GetLastDamageTime();
	void SetLastDamageTime(float LastDamageTime);
	unsigned int GetDamageIndex();
	void SetDamageIndex(unsigned int DamageIndex);
	float GetAbsorbedForce();
	void SetAbsorbedForce(float AbsorbedForce);
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	float GetDamagePercent();
	bool WillDamage();
	unsigned int GetDamageIndexForForce(float Force);
	unsigned int GetDamageIndexForTime(float Time);
	void SetLastTeamTouch2(unsigned char InLastTeamTouch);
	void ForceDamageIndex(unsigned int InIndex);
	void SetDamageIndex2(unsigned int InIndex);
	void OnCarTouch(CarWrapper HitCar, unsigned char HitType);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};