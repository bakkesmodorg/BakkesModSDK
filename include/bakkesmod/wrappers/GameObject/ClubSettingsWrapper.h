#pragma once
#include "../Engine/ObjectWrapper.h"
#include "../Engine/UnrealStringWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT ClubSettingsWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ClubSettingsWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetClubName();
	UnrealStringWrapper GetClubTag();
	int GetPrimaryColor();
	int GetAccentColor();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};