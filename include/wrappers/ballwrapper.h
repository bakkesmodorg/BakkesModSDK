#pragma once
#include "wrapperstructs.h"
#include "actorwrapper.h"

class BAKKESMOD_PLUGIN_IMPORT BallWrapper : public ActorWrapper
{

public:
	BallWrapper(std::uintptr_t mem);
	BallWrapper(const BallWrapper& other);
	BallWrapper& operator=(BallWrapper rhs);
	~BallWrapper();
	float GetLastTouchTime();

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

