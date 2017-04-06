#pragma once
#include "actorwrapper.h"
#include "boostwrapper.h"
#include "wrapperstructs.h"

class PriWrapper;

class BAKKESMOD_PLUGIN_IMPORT CarWrapper : public ActorWrapper
{
public:
	CarWrapper(std::uintptr_t mem);
	CarWrapper(const CarWrapper& other);
	CarWrapper& operator=(CarWrapper rhs);
	~CarWrapper();
	//void Stop();

	bool IsDriving();
	bool IsOnGround();

	bool HasJumped();
	bool HasDoubleJumped();

	bool IsBoostCheap();
	void SetBoostCheap(bool b);
	void SetCarRotation(Rotator rotation);
	void EnableGravity(bool enable);
	BoostWrapper GetBoost();
	void ForceBoost(bool force);
	string GetOwnerName();
	//bool IsBoostCheap();
	//void SetBoostCheap(bool bBoost);
	void Unfreeze();
	PriWrapper GetPRI();

	ControllerInput GetInput();
	void SetInput(ControllerInput input);
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

