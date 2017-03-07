#pragma once
#include "wrapperstructs.h"
class BAKKESMOD_PLUGIN_IMPORT BoostWrapper
{


public:
	BoostWrapper(std::uintptr_t mem);
	BoostWrapper(const BoostWrapper& other);
	BoostWrapper& operator=(BoostWrapper rhs);
	~BoostWrapper();

	float GetMaxBoostAmount();
	float GetStartBoostAmount();

	float GetCurrentBoostAmount();
	void SetBoostAmount(float amount);
	void AddBoostAmount(float amount);

	bool IsUnlimitedBoost();
	void SetUnlimitedBoost(bool unlimited);

	bool IsActive();
	void SetActive(bool act);
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

