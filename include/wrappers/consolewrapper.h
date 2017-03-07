#pragma once
#include "../shared.h"

struct LogLevel {
	int r, g, b, a;
};
static LogLevel LOG_INFO = { 255, 255, 255, 255 };
static LogLevel LOG_WARN = { 255, 165, 0, 255 };
static LogLevel LOG_ERROR = { 240, 10, 10, 255 };


class BAKKESMOD_PLUGIN_IMPORT ConsoleWrapper
{

public:
	ConsoleWrapper(std::uintptr_t mem);
	ConsoleWrapper(const ConsoleWrapper& other);
	ConsoleWrapper& operator=(ConsoleWrapper rhs);
	~ConsoleWrapper();

	void executeCommand(std::string command);
	void unregisterNotifier(std::string cvar, CVarChange notifier);
	void registerNotifier(std::string cvar, CVarChange notifier); //public
	void registerCvar(std::string cvar, std::string defaultValue = "0"); //public 
	std::string getCvarValue(std::string cvar, std::string defaultValue = ""); //public
	int getCvarInt(std::string cvar, int defaultValue = 0); //public
	float getCvarFloat(std::string cvar, float defaultValue = 0.0f); //public
	bool getCvarBool(std::string cvar, bool defaultValue = false); //public
	void setCvar(std::string cvar, std::string value); //public
	void log(std::string text, LogLevel lvl = LOG_INFO);

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};
