#pragma once
#include <memory>
#include <cstdint>
#include "ballwrapper.h"
#include "carwrapper.h"

class BAKKESMOD_PLUGIN_IMPORT GameEventWrapper : public ActorWrapper
{

public:
	CONSTRUCTORS(GameEventWrapper)
	BallWrapper GetBall();
	bool IsTraining(int type);
	bool IsInFreePlay();
	bool IsServer();
	void KickBots();
	CarWrapper GetPRICar(int idx);

private:
	PIMPL
};

