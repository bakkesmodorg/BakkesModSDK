#pragma once

#include <map>
#include <queue>
#include <mutex>

#include "GameEventWrapper.h"
#include "tutorialwrapper.h"
#include "serverwrapper.h"
#include "replaydirectorwrapper.h"

class BAKKESMOD_PLUGIN_IMPORT GameWrapper
{
public:
	GameWrapper(std::uintptr_t mem);
	GameWrapper(const GameWrapper& other);
	GameWrapper& operator=(GameWrapper rhs);
	~GameWrapper();

	bool IsInTutorial();
	bool IsInReplay();
	bool IsInCustomTraining();

	GameEventWrapper				GetGameEvent();
	TutorialWrapper					GetGameEventAsTutorial();
	ServerWrapper					GetGameEventAsServer();
	CarWrapper						GetLocalCar();
	ServerWrapper					GetReplayGameEvent();
	ReplayDirectorWrapper			GetReplayDirector();
	void							SetTimeout(std::function<void(GameWrapper*)> theLambda, long long time); //time in MS

	//Must be used when calling game functions or changing game data from a thread
	void							Execute(std::function<void(GameWrapper*)> theLambda);

public:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

