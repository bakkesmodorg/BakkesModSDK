#pragma once
#include "WrapperStructs.h"
class BAKKESMOD_PLUGIN_IMPORT SettingsWrapper
{
public:
	SettingsWrapper();
	~SettingsWrapper();
	ProfileCameraSettings GetCameraSettings();
	std::map<std::string, std::string> GetPCBindings();
	std::map<std::string, std::string> GetGamepadBindings();
	GamepadSettings GetGamepadSettings();
	VideoSettings GetVideoSettings();
};

