#pragma once
#include "../plugin/bakkesmodsdk.h"
#include <vector>
#include <typeindex>
#include <string>
#include "cvarwrapper.h"

typedef void (*commandNotifier)(std::vector<std::string>);

class BAKKESMOD_PLUGIN_IMPORT CVarManagerWrapper
{
public:
	CVarManagerWrapper(std::uintptr_t mem, std::type_index pluginIdx);
	CVarManagerWrapper(const CVarManagerWrapper& other);
	CVarManagerWrapper& operator=(CVarManagerWrapper rhs);
	~CVarManagerWrapper();

	void executeCommand(std::string command, bool log = true);
	void registerNotifier(std::string cvar, commandNotifier notifier);
	void registerNotifier(std::string cvar, std::function<void(std::vector<std::string>)> notifier);

	CVarWrapper registerCvar(std::string cvar, std::string defaultValue, std::string desc = "", bool searchAble = true, bool hasMin = false, float min = 0, bool hasMax = false, float max = 0, bool saveToCfg = true);
	
	void log(std::string text);
	CVarWrapper getCvar(std::string cvar);

	void backupCfg(std::string path);
	void backupBinds(std::string path);
	void loadCfg(std::string path);
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

