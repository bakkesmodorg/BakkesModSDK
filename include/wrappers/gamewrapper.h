#pragma once

#include <map>
#include <queue>
#include <mutex>

#include "GameEventWrapper.h"
#include "tutorialwrapper.h"
#include "serverwrapper.h"
#include "calculationhelpers.h"
#include "camerawrapper.h"
#include "replaywrapper.h"
#include "canvaswrapper.h"

class BAKKESMOD_PLUGIN_IMPORT GameWrapper
{

public:
	GameWrapper(std::uintptr_t mem, long pluginType);
	GameWrapper(const GameWrapper& other);
	GameWrapper& operator=(GameWrapper rhs);
	~GameWrapper();

	bool IsInTutorial();
	bool IsInReplay();
	bool IsInCustomTraining();

	GameEventWrapper				GetGameEvent();
	TutorialWrapper					GetGameEventAsTutorial();
	ServerWrapper					GetGameEventAsServer();
	ReplayWrapper					GetGameEventAsReplay();

	CarWrapper						GetLocalCar();
	CameraWrapper					GetCamera();
	
	void							SetTimeout(std::function<void(GameWrapper*)> theLambda, long long time); //time in MS
	void							Execute(std::function<void(GameWrapper*)> theLambda); //Use this when calling from a different thread
	void							RegisterDrawable(DrawCallback callback);
	string							GetFNameByIndex(int index);
	

	ActorWrapper					GetSolidHook();
	CalculationHelpers				GetCalculator();
public:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

