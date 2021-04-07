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
	void registerNotifier(std::string cvar, commandNotifier notifier, std::string description, unsigned char permissions);
	void registerNotifier(std::string cvar, std::function<void(std::vector<std::string>)> notifier, std::string description, unsigned char permissions);
	bool removeNotifier(std::string cvar);

	CVarWrapper registerCvar(std::string cvar, std::string defaultValue, std::string desc = "", bool searchAble = true, bool hasMin = false, float min = 0, bool hasMax = false, float max = 0, bool saveToCfg = true);
	bool removeCvar(std::string cvar);

	void log(std::string text);
    void log(std::wstring text);
	CVarWrapper getCvar(std::string cvar);

	std::string getBindStringForKey(std::string key);
	void setBind(std::string key, std::string command);
	void removeBind(std::string key);
	std::string getAlias(std::string alias);
	void setAlias(std::string key, std::string script);

	void backupCfg(std::string path);
	void backupBinds(std::string path);
	void loadCfg(std::string path);
private:
    PIMPL
};

