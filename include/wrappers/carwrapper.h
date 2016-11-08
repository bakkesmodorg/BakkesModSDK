#pragma once
#include "actorwrapper.h"
#include "boostwrapper.h"
#include "wrapperstructs.h"
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

	void SetCarRotation(Rotator rotation);
	void EnableGravity(bool enable);
	BoostWrapper GetBoost();

	void Unfreeze();
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

