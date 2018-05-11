#pragma once

#include <map>
#include <queue>
#include <mutex>
#include <typeindex>
#include "canvaswrapper.h"

class GameEventWrapper;
class TutorialWrapper;
class ServerWrapper;
class CameraWrapper;
class ReplayServerWrapper;
class CanvasWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameWrapper
{
public:
	GameWrapper(std::uintptr_t mem, long pluginType, std::type_index idx);
	GameWrapper(const GameWrapper& other);
	GameWrapper& operator=(GameWrapper rhs);
	~GameWrapper();

	bool IsInGame();
	bool IsInTutorial();
	bool IsInReplay();
	bool IsInCustomTraining();
	bool IsSpectatingInOnlineGame();

	TutorialWrapper					GetGameEventAsTutorial();
	ServerWrapper					GetGameEventAsServer();
	ReplayServerWrapper				GetGameEventAsReplay();

	CarWrapper						GetLocalCar();
	CameraWrapper					GetCamera();
	
	void							SetTimeout(std::function<void(GameWrapper*)> theLambda, float time); //time in seconds
	void							Execute(std::function<void(GameWrapper*)> theLambda); //Use this when calling from a different thread
	void							RegisterDrawable(std::function<void(CanvasWrapper)> callback);
	void							UnregisterDrawables(); //Can only unregister every drawable for now, sorry!
	string							GetFNameByIndex(int index);
	int								GetFNameIndexByString(string name);
	void							HookEvent(string eventName, std::function<void(std::string eventName)> callback);
	void							HookEventPost(string eventName, std::function<void(std::string eventName)> callback);
	void							RegisterBot(CARBODY car, std::function<void(float deltaTime, ControllerInput* inputs, CarWrapper* ownedCar, ServerWrapper* game)> tickfunc, string botName, bool overridePlayer);

	void							LogToChatbox(string text);
	bool							IsKeyPressed(int keyName);
	void							ExecuteUnrealCommand(string command);
public:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

