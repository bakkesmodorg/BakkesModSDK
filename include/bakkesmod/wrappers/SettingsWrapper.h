#pragma once
#include "WrapperStructs.h"

class BAKKESMOD_PLUGIN_IMPORT SettingsWrapper
{
public:
	SettingsWrapper();
	~SettingsWrapper();
	ProfileCameraSettings GetCameraSettings();
	CameraSave GetCameraSaveSettings();

	[[deprecated("Use GetAllPCBindings instead")]]
	std::map<std::string, std::string> GetPCBindings();

	[[deprecated("Use GetAllGamepadBindings instead")]]
	std::map<std::string, std::string> GetGamepadBindings();

	std::vector<std::pair<std::string, std::string>> GetAllPCBindings();
	std::vector<std::pair<std::string, std::string>> GetAllGamepadBindings();

	GamepadSettings GetGamepadSettings();
	VideoSettings GetVideoSettings();



	_NODISCARD bool GetForceDefaultColors() const;
	void SetForceDefaultColors(bool value);
	
};

