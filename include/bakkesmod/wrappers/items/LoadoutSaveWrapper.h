#pragma once

#include <string>
#include "LoadoutSetWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT LoadoutSaveWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(LoadoutSaveWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	_NODISCARD LoadoutSetWrapper GetPreset(const std::string& name) const;
	_NODISCARD LoadoutSetWrapper GetPreset(int index) const;
	_NODISCARD ArrayWrapper<LoadoutSetWrapper> GetPresets() const;

	void SetPreviewTeam(int team);
	_NODISCARD int GetPreviewTeam() const;
	_NODISCARD LoadoutSetWrapper GetEquippedLoadout() const;
	void RenamePreset(const LoadoutSetWrapper& preset_wrapper, const std::string& new_name);
	void EquipPreset(const LoadoutSetWrapper& preset) const;
	void DeletePreset(const LoadoutSetWrapper& preset_wrapper);
	_NODISCARD LoadoutSetWrapper AddPreset();
	void SwapPreset(const LoadoutSetWrapper& a, const LoadoutSetWrapper& b);
	_NODISCARD int GetIndex(const LoadoutSetWrapper& preset_wrapper) const;
	
private:
	PIMPL
};

