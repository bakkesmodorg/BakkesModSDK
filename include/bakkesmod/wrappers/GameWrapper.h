#pragma once
#pragma warning(push)
#pragma warning(disable:4251)

#include <map>
#include <queue>
#include <mutex>
#include <typeindex>
#include "canvaswrapper.h"
#include "mmrwrapper.h"

#ifdef __cpp_lib_filesystem
#include <filesystem>
#endif
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
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameWrapper
{
public:
	GameWrapper(std::uintptr_t mem, long pluginType, std::type_index idx);
	GameWrapper(const GameWrapper& other);
	GameWrapper& operator=(GameWrapper rhs);
	~GameWrapper();

	bool IsInGame(); // returns true if the game is exhibition, LAN, a private match, or an online match
			 // To find out if you're in exhibition or LAN, (!IsInOnlineGame() && IsInGame())
	bool IsInOnlineGame(); // returns true if the game is a private match or an online match
	//bool IsInTutorial(); //Uncomment this later, but for now dont let plugins compile which use this as they most likely rely on broken functions
	bool IsInFreeplay(); // returns true only if in freeplay
	bool IsInReplay(); // returns true only if in a replay
	bool IsInCustomTraining(); // returns true only if in custom training
	bool IsSpectatingInOnlineGame(); // returns false. The function is currently broken

	bool IsPaused(); // returns true if the game is paused
	bool IsUsingEpicVersion(); // returns true if the player is on epic
	bool IsUsingSteamVersion(); // returns true if the player is on steam

	int GetSteamVersion(); // returns steam game version
	std::string GetPsyBuildID(); // returns build ID of game version

	ServerWrapper					GetOnlineGame(); // returns the serverwrapper of the current game. Returns null if not in an online game
	//TutorialWrapper				GetGameEventAsTutorial();
	ServerWrapper					GetGameEventAsServer(); // returns the serverwrapper of the current game. Returns null if not in a local game
	ReplayServerWrapper				GetGameEventAsReplay(); // returns the serverwrapper of the current game. Returns null if not in a replay

	MMRWrapper						GetMMRWrapper(); 
	CarWrapper						GetLocalCar(); // returns the car of the player. Returns null if you are in spectate, goal replay, or demolished
	CameraWrapper					GetCamera();
	EngineTAWrapper					GetEngine();
	PluginManagerWrapper			GetPluginManager();
	GuiManagerWrapper				GetGUIManager();
	PlayerControllerWrapper			GetPlayerController(); // returns controller of the player
	ItemsWrapper					GetItemsWrapper();
	void							OverrideParams(void* src, size_t memsize);

	void							SetTimeout(std::function<void(GameWrapper*)> theLambda, float time); // stops and calls a function. Waits time seconds before executing 
	void							Execute(std::function<void(GameWrapper*)> theLambda); //Use this when calling from a different thread
	void							RegisterDrawable(std::function<void(CanvasWrapper)> callback); // registers a function to draw on screen. See CanvasWrapper for how to draw
	void							UnregisterDrawables(); // Removes all drawing functions created by this plugin. Can only unregister every drawable for now, sorry!
	std::string						GetFNameByIndex(int index);
	int								GetFNameIndexByString(std::string name);

	void							HookEvent(std::string eventName, std::function<void(std::string eventName)> callback); // calls a function whenever this event happens. 
																		       //Is inconsistent with timing, so HookEventPost is preferred
	void							UnhookEvent(std::string eventName); // stops calling functions from this plugin when this event happens

	void							HookEventPost(std::string eventName, std::function<void(std::string eventName)> callback); // calls a function after this event happens
	void							UnhookEventPost(std::string eventName); // stops calling functions from this plugin when this event happens

	void							LogToChatbox(std::string text, std::string sender="BAKKESMOD"); // writes to the chat window. Only works in offline modes

	/*
	Will queue up loading of a texture into memory, only has to be done once, after this it will persistently be stored in memory.
	Loading will be done at next toast render frame, any errors will be printed to the console.
	Supported file formats: Whatever D3DXCreateTextureFromFile supports.
	*/
	void							LoadToastTexture(std::string name, std::string path);
	void							LoadToastTexture(std::string name, std::wstring path);
#ifdef __cpp_lib_filesystem
	void							LoadToastTexture(std::string name, std::filesystem::path path);
#endif
	/*
	Texture is the name of the texture given in LoadToastTexture, not the path! "default" will show the normal BakkesMod logo
	*/
	void							Toast(std::string title, std::string text, std::string texture = "default", float timeout = 3.5f, uint8_t toastType = 0, float width = 290.f, float height = 60.f);
	bool							IsKeyPressed(int keyName);
	int								IsCursorVisible(); // 1 if due to RL, 2 if ImGui
	void							ExecuteUnrealCommand(std::string command);
	std::string 					GetRandomMap();
	std::string 					GetCurrentMap();
	unsigned long long				GetSteamID(); // depreciated, use GetUniqueID
	std::string					GetEpicID(); // depreciated, use GetUniqueID
	UniqueIDWrapper					GetUniqueID(); // returns a wrapper which handles the complexities of both epic and steam players and their ids
	UnrealStringWrapper				GetPlayerName();
	ClubDetailsWrapper				GetLocalClub();
	SequenceWrapper					GetMainSequence();

    Vector2							GetScreenSize(); // returns x and y values of the current screen resolution
    float							GetSafeZoneRatio();
    float							GetUIScale();
    unsigned int					GetbMetric();
    UnrealStringWrapper				GetUILanguage();
    bool							GetbColorBlind();
	// Path utilities
#ifdef __cpp_lib_filesystem // requires c++17
	std::filesystem::path			GetBakkesModPath(); // returns path to bakkesmod, %appdata%/bakkesmod/bakkesmod
	std::filesystem::path			GetDataFolder(); // returns path to bakkesmod/data, %appdata%/bakkesmod/bakkesmod/data
	std::filesystem::path			FixRelativePath(std::filesystem::path path); // sets relative location so you can read and write files anywhere. 
											     // using the bakkesmod folder is highly recommended though
#endif
	std::wstring					GetBakkesModPathW(); // returns wstring of "%appdata%/bakkesmod/bakkesmod"
	std::wstring					GetDataFolderW(); // returns wstring of "%appdata%/bakkesmod/bakkesmod/data"

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
