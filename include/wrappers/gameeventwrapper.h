#pragma once
#include <memory>
#include <cstdint>
#include "ballwrapper.h"


class BAKKESMOD_PLUGIN_IMPORT GameEventWrapper
{

public:
	GameEventWrapper(std::uintptr_t mem);
	GameEventWrapper(const GameEventWrapper& other);
	GameEventWrapper& operator=(GameEventWrapper rhs);
	~GameEventWrapper();
	BallWrapper GetBall();
	bool IsTraining(int type);
	bool IsInFreePlay();
	bool IsServer();

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

