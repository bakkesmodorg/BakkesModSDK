#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "../imgui/imgui.h"
#include <tuple>

#define BMCORE_INTERNAL_IMPORT __declspec(dllimport)
#pragma comment (lib, "bakkesmod.lib")

#define RESULT_DECL void*const result

namespace BMCore
{
    typedef unsigned long long PluginID;

    typedef std::function<void(UObject * caller, UFunction * func, void* params)> FunctionCallbackPre;
    typedef std::function<void(UObject * caller, UFunction * func, void* params, RESULT_DECL)> FunctionCallbackPost;

    struct CallbackDefPre {
        std::type_index registrar;
        FunctionCallbackPre callback;
    };
    struct CallbackDefPost {
        std::type_index registrar;
        FunctionCallbackPost callback;
    };

    typedef std::function<void()> TimeoutCallback;
    typedef std::function<void(UCanvas * canvas)> RenderCallback;
    typedef std::function<void(float deltaTime, ControllerInput * inputs, CarWrapper * ownedCar, ServerWrapper * game)> tickFunc;

    typedef std::function<void(std::vector<std::string>)> CvarNotifier;
    typedef std::function<void(std::string oldValue, void* cvarNow)> CvarValueChangedVoid;
    
    typedef std::function<void(bool, int, int, void*)> TextureLoadedCallback;

    BMCORE_INTERNAL_IMPORT bool IsInOnlineGame();
    BMCORE_INTERNAL_IMPORT bool IsINotInOnlineGameOrSpectating();
    BMCORE_INTERNAL_IMPORT bool CanModify();
    BMCORE_INTERNAL_IMPORT void* GetImGuiStyle();
    BMCORE_INTERNAL_IMPORT std::tuple<int, ImFont*> LoadFont(std::string name, std::string path, int size, const ImFontConfig* fontConfig, const ImWchar* glyphRanges);
    BMCORE_INTERNAL_IMPORT ImFont* GetFont(std::string name);
    BMCORE_INTERNAL_IMPORT void LoadTexture(std::string path, TextureLoadedCallback onLoadedCb);
    BMCORE_INTERNAL_IMPORT void* ImGuiGetCurrentContext();
    BMCORE_INTERNAL_IMPORT APlayerControllerBase_TA* GetPlayerController();
    BMCORE_INTERNAL_IMPORT UGameData_TA* GetGameData();

    BMCORE_INTERNAL_IMPORT int IsCursorVisible();
    BMCORE_INTERNAL_IMPORT unsigned long long GetSteamID();
    BMCORE_INTERNAL_IMPORT bool IsSyncing(FUniqueNetId id);
    BMCORE_INTERNAL_IMPORT bool IsSynced(FUniqueNetId id, int playlistID);
    BMCORE_INTERNAL_IMPORT bool IsRanked(int playlistID);
    BMCORE_INTERNAL_IMPORT FPlayerSkillRating GetPlayerSkillRating(FUniqueNetId id, int playlistID);
    BMCORE_INTERNAL_IMPORT float GetPlayerMMR(FUniqueNetId id, int playlistID);
    BMCORE_INTERNAL_IMPORT float CalculateMMR(FPlayerSkillRating sr, bool);
    BMCORE_INTERNAL_IMPORT int GetCurrentPlaylist();

    BMCORE_INTERNAL_IMPORT std::vector<std::shared_ptr<BakkesMod::Plugin::LoadedPlugin>>* GetLoadedPlugins(void* pluginMgr);
    BMCORE_INTERNAL_IMPORT void* GetPluginManager();

    BMCORE_INTERNAL_IMPORT AGameEvent_Soccar_TA* GetSoccarGameEvent();
    BMCORE_INTERNAL_IMPORT bool IsInOnlineGame();
    BMCORE_INTERNAL_IMPORT AGameEvent_Soccar_TA* GetOnlineGame();
    BMCORE_INTERNAL_IMPORT AGameEvent_Soccar_TA* GetTutorial();
    BMCORE_INTERNAL_IMPORT AGameInfo_Replay_TA* GetReplayGameInfo();
    BMCORE_INTERNAL_IMPORT AGameEvent_TrainingEditor_TA* GetCustomTraining();

    BMCORE_INTERNAL_IMPORT std::string GetRandomMap();
    BMCORE_INTERNAL_IMPORT std::string GetCurrentMap();

    BMCORE_INTERNAL_IMPORT void RegisterTimeout(float timeRemaining, TimeoutCallback callback, std::type_index owner);
    BMCORE_INTERNAL_IMPORT void RegisterTimeout(float timeRemaining, TimeoutCallback callback, unsigned long long owner);
    BMCORE_INTERNAL_IMPORT void RegisterDrawable(std::type_index index, RenderCallback callback, int layer);
    BMCORE_INTERNAL_IMPORT void RegisterDrawable(unsigned long long index, RenderCallback callback, int layer);
    BMCORE_INTERNAL_IMPORT void UnregisterDrawable(std::type_index index);
    BMCORE_INTERNAL_IMPORT void UnregisterDrawable(unsigned long long id);

    BMCORE_INTERNAL_IMPORT void OverrideParams(void* src, size_t memsize);
    BMCORE_INTERNAL_IMPORT void register_hook(std::string func, FunctionCallbackPre cb, std::type_index ti);
    BMCORE_INTERNAL_IMPORT void register_hook(std::string func, FunctionCallbackPre cb, unsigned long long pluginId);
    BMCORE_INTERNAL_IMPORT void unregister_hook(std::string funcname, std::type_index ti);
    BMCORE_INTERNAL_IMPORT void unregister_hook(std::string funcname, unsigned long long id);
    BMCORE_INTERNAL_IMPORT void register_hook_post(std::string func, FunctionCallbackPost callbackDef);
    BMCORE_INTERNAL_IMPORT void register_hook_post(std::string func, CallbackDefPost callbackDef);
    BMCORE_INTERNAL_IMPORT void register_hook_post(std::string func, FunctionCallbackPost cb, std::type_index ti);
    BMCORE_INTERNAL_IMPORT void register_hook_post(std::string func, FunctionCallbackPost cb, unsigned long long ti);
    BMCORE_INTERNAL_IMPORT void unregister_hook_post(std::string funcname, std::type_index ti);
    BMCORE_INTERNAL_IMPORT void unregister_hook_post(std::string funcname, unsigned long long id);

    BMCORE_INTERNAL_IMPORT void LogToChatbox(std::string text, std::string sender);

    BMCORE_INTERNAL_IMPORT std::wstring bmcore_s2ws(const std::string& str);

    BMCORE_INTERNAL_IMPORT void ToastManagerLoadTexture(std::string name, std::string path);
    BMCORE_INTERNAL_IMPORT void ToastManagerToast(std::string title, std::string text, std::string texture, float timeout, uint8_t toastType, float width, float height);

    BMCORE_INTERNAL_IMPORT void* RegisterCvar(std::string cvar, std::string defaultValue, std::string desc, bool searchAble, bool hasMin, float min, bool hasMax, float max, bool saveToCfg, std::type_index index);
    BMCORE_INTERNAL_IMPORT void* RegisterCvar(std::string cvar, std::string defaultValue, std::string desc, bool searchAble, bool hasMin, float min, bool hasMax, float max, bool saveToCfg, unsigned long long index);
    BMCORE_INTERNAL_IMPORT bool RemoveCvar(std::string cvar, std::type_index index);
    BMCORE_INTERNAL_IMPORT bool RemoveCvar(std::string cvar, unsigned long long index);
    BMCORE_INTERNAL_IMPORT void* GetCvar(std::string cv);
    BMCORE_INTERNAL_IMPORT void log(std::string pluginName, std::string text);
    BMCORE_INTERNAL_IMPORT void log(unsigned long long pluginID, std::string text);

    BMCORE_INTERNAL_IMPORT void ExecuteCommand(std::string command, bool log);
    BMCORE_INTERNAL_IMPORT void RegisterNotifier(std::string s, CvarNotifier notifier, std::type_index registrar_index, std::string description, bool searchAble, unsigned char permission_flags);
    BMCORE_INTERNAL_IMPORT void RegisterNotifier(std::string s, CvarNotifier notifier, unsigned long long registrar_index, std::string description, bool searchAble, unsigned char permission_flags);
    BMCORE_INTERNAL_IMPORT bool RemoveNotifier(std::string s, std::type_index registrar_index);
    BMCORE_INTERNAL_IMPORT bool RemoveNotifier(std::string s, unsigned long long registrar_index);
    BMCORE_INTERNAL_IMPORT std::string GetBind(std::string key);
    BMCORE_INTERNAL_IMPORT void AddBind(std::string key, std::string command);
    BMCORE_INTERNAL_IMPORT std::string GetAlias(std::string aliasName);
    BMCORE_INTERNAL_IMPORT void SetAlias(std::string aliasName, std::string script);
    BMCORE_INTERNAL_IMPORT void LoadCfg(std::string filename);
    BMCORE_INTERNAL_IMPORT void SaveCfg(std::string filePath = "./bakkesmod/cfg/config.cfg");
    BMCORE_INTERNAL_IMPORT void SaveBinds(std::string filePath = "./bakkesmod/cfg/binds.cfg");


    BMCORE_INTERNAL_IMPORT std::string GetCVarName(void* cvar);
    BMCORE_INTERNAL_IMPORT std::string GetCVarDescription(void* cvar);
    BMCORE_INTERNAL_IMPORT bool HasMinimum(void* cvar);
    BMCORE_INTERNAL_IMPORT bool HasMaximum(void* cvar);
    BMCORE_INTERNAL_IMPORT float GetMinimum(void* cvar);
    BMCORE_INTERNAL_IMPORT float GetMaximum(void* cvar);
    BMCORE_INTERNAL_IMPORT bool IsHidden(void* cvar);
    BMCORE_INTERNAL_IMPORT bool ShouldSaveToCfg(void* cvar);

    BMCORE_INTERNAL_IMPORT int GetIntValue(void* cvar);
    BMCORE_INTERNAL_IMPORT float GetFloatValue(void* cvar);
    BMCORE_INTERNAL_IMPORT bool GetBoolValue(void* cvar);
    BMCORE_INTERNAL_IMPORT LinearColor GetColorValue(void* cvar);
    BMCORE_INTERNAL_IMPORT const std::string GetDefaultValue(void* cvar);
    BMCORE_INTERNAL_IMPORT std::string GetStringValue(void* cvar);
    BMCORE_INTERNAL_IMPORT std::string GetDescription(void* cvar);
    BMCORE_INTERNAL_IMPORT void ResetToDefault(void* cvar);
    BMCORE_INTERNAL_IMPORT void Notify(void* cvar);
    BMCORE_INTERNAL_IMPORT void SetValue(void* cvar, std::string value, bool notify = true);
    BMCORE_INTERNAL_IMPORT void SetValue(void* cvar, int value);
    BMCORE_INTERNAL_IMPORT void SetValue(void* cvar, float value);
    BMCORE_INTERNAL_IMPORT void SetValue(void* cvar, LinearColor value);
    BMCORE_INTERNAL_IMPORT void AddOnValueChanged(void* cvar, CvarValueChangedVoid, std::type_index idx);
    BMCORE_INTERNAL_IMPORT void AddOnValueChanged(void* cvar, CvarValueChangedVoid, unsigned long long pluginId);
    BMCORE_INTERNAL_IMPORT void* AddOnValueChanged(void* cvar, CvarValueChangedVoid);
    BMCORE_INTERNAL_IMPORT int RemoveOnValueChanged(void* cvar, std::type_index idx);
    BMCORE_INTERNAL_IMPORT int RemoveOnValueChanged(void* cvar, unsigned long long pluginId);
    BMCORE_INTERNAL_IMPORT void BindTo(void* cvar, std::shared_ptr<int> var, std::type_index idx);
    BMCORE_INTERNAL_IMPORT void BindTo(void* cvar, std::shared_ptr<float> var, std::type_index idx);
    BMCORE_INTERNAL_IMPORT void BindTo(void* cvar, std::shared_ptr<std::string> var, std::type_index idx);
    BMCORE_INTERNAL_IMPORT void BindTo(void* cvar, std::shared_ptr<bool> var, std::type_index idx);
    BMCORE_INTERNAL_IMPORT void BindTo(void* cvar, std::shared_ptr<LinearColor> var, std::type_index idx);
}
