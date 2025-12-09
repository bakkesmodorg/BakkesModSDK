#pragma once

class BAKKESMOD_PLUGIN_IMPORT CameraSettingsActorWrapper : public ActorWrapper
{
public:
	CONSTRUCTORS(CameraSettingsActorWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD PriWrapper GetPri() const;
	_NODISCARD ProfileCameraSettings GetProfileSettings() const;
	_NODISCARD void SetProfileSettings(const ProfileCameraSettings& profileCameraSettings);
	
	_NODISCARD bool GetUsingBehindView() const;
	void SetUsingBehindView(bool bUsingBehindView);

private:
	PIMPL
	
};
