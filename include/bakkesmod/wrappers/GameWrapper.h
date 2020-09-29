#pragma once
#pragma warning(push)
#pragma warning(disable:4251)

#include <map>
#include <queue>
#include <mutex>
#include <typeindex>
#include "canvaswrapper.h"
#include "mmrwrapper.h"
class GameEventWrapper;
class TutorialWrapper;
class ServerWrapper;
class CameraWrapper;
class ReplayServerWrapper;
class CanvasWrapper;
class CarWrapper;
class EngineTAWrapper;
class PlayerControllerWrapper;
class PluginManagerWrapper;
class GuiManagerWrapper;
class BindingsWrapper;
class SequenceWrapper;
class ItemsWrapper;
class ClubDetailsWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameWrapper
{
public:
	GameWrapper(std::uintptr_t mem, long pluginType, std::type_index idx);
	GameWrapper(const GameWrapper& other);
	GameWrapper& operator=(GameWrapper rhs);
	~GameWrapper();

	bool IsInGame();
	bool IsInOnlineGame();
	//bool IsInTutorial(); //Uncomment this later, but for now dont let plugins compile which use this as they most likely rely on broken functions
	bool IsInFreeplay();
	bool IsInReplay();
	bool IsInCustomTraining();
	bool IsSpectatingInOnlineGame();

	bool IsPaused();


	ServerWrapper					GetOnlineGame();
	//TutorialWrapper				GetGameEventAsTutorial();
	ServerWrapper					GetGameEventAsServer();
	ReplayServerWrapper				GetGameEventAsReplay();

	MMRWrapper						GetMMRWrapper();
	CarWrapper						GetLocalCar();
	CameraWrapper					GetCamera();
	EngineTAWrapper					GetEngine();
	PluginManagerWrapper			GetPluginManager();
	GuiManagerWrapper				GetGUIManager();
	PlayerControllerWrapper			GetPlayerController();
	ItemsWrapper					GetItemsWrapper();
	void							OverrideParams(void* src, size_t memsize);

	void							SetTimeout(std::function<void(GameWrapper*)> theLambda, float time); //time in seconds, subject to change to std::shared_ptr<GameWrapper>
	void							Execute(std::function<void(GameWrapper*)> theLambda); //Use this when calling from a different thread
	void							RegisterDrawable(std::function<void(CanvasWrapper)> callback);
	void							UnregisterDrawables(); //Can only unregister every drawable for now, sorry!
	std::string						GetFNameByIndex(int index);
	int								GetFNameIndexByString(std::string name);

	void							HookEvent(std::string eventName, std::function<void(std::string eventName)> callback);
	void							UnhookEvent(std::string eventName);

	void							HookEventPost(std::string eventName, std::function<void(std::string eventName)> callback);
	void							UnhookEventPost(std::string eventName);

	void							LogToChatbox(std::string text, std::string sender="BAKKESMOD");

	/*
	Will queue up loading of a texture into memory, only has to be done once, after this it will persistently be stored in memory.
	Loading will be done at next toast render frame, any errors will be printed to the console.
	Supported file formats: Whatever D3DXCreateTextureFromFile supports.
	*/
	void							LoadToastTexture(std::string name, std::string path);

	/*
	Texture is the name of the texture given in LoadToastTexture, not the path! "default" will show the normal BakkesMod logo
	*/
	void							Toast(std::string title, std::string text, std::string texture = "default", float timeout = 3.5f, uint8_t toastType = 0, float width = 290.f, float height = 60.f);
	bool							IsKeyPressed(int keyName);
	int								IsCursorVisible(); // 1 if due to RL, 2 if ImGui
	void							ExecuteUnrealCommand(std::string command);
	std::string 					GetRandomMap();
	std::string 					GetCurrentMap();
	unsigned long long				GetSteamID();
	class UnrealStringWrapper				GetPlayerName();
	ClubDetailsWrapper				GetLocalClub();
	SequenceWrapper					GetMainSequence();

    Vector2							GetScreenSize();
    float							GetSafeZoneRatio();
    float							GetUIScale();
    unsigned int					GetbMetric();
    UnrealStringWrapper				GetUILanguage();
    bool							GetbColorBlind();

	template<typename T, typename std::enable_if<std::is_base_of<ObjectWrapper, T>::value>::type* = nullptr>
	void							HookEventWithCaller(std::string eventName, std::function<void(T caller, void* params, std::string eventName)> callback);
	template<typename T, typename std::enable_if<std::is_base_of<ObjectWrapper, T>::value>::type* = nullptr>
	void							HookEventWithCallerPost(std::string eventName, std::function<void(T caller, void* params, std::string eventName)> callback);
public:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};
#include "includes.h"
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCaller<ServerWrapper>(std::string eventName, std::function<void(ServerWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCaller<ActorWrapper>(std::string eventName, std::function<void(ActorWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCaller<CarWrapper>(std::string eventName, std::function<void(CarWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCaller<CarComponentWrapper>(std::string eventName, std::function<void(CarComponentWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCaller<PlayerControllerWrapper>(std::string eventName, std::function<void(PlayerControllerWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCaller<BallWrapper>(std::string eventName, std::function<void(BallWrapper caller, void* params, std::string eventName)> callback);

extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCallerPost<ActorWrapper>(std::string eventName, std::function<void(ActorWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCallerPost<ServerWrapper>(std::string eventName, std::function<void(ServerWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCallerPost<CarWrapper>(std::string eventName, std::function<void(CarWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCallerPost<CarComponentWrapper>(std::string eventName, std::function<void(CarComponentWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCallerPost<PlayerControllerWrapper>(std::string eventName, std::function<void(PlayerControllerWrapper caller, void* params, std::string eventName)> callback);
extern template void BAKKESMOD_PLUGIN_IMPORT GameWrapper::HookEventWithCallerPost<BallWrapper>(std::string eventName, std::function<void(BallWrapper caller, void* params, std::string eventName)> callback);
#pragma warning(pop)