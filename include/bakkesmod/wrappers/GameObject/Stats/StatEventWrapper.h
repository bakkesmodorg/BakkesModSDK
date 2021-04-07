#pragma once
#include "../../Engine/ObjectWrapper.h"
#include "../../Engine/UnrealStringWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT StatEventWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(StatEventWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int GetPoints();
	float GetCooldownSeconds();
	unsigned long GetbAddToScore();
	unsigned long GetbIsLeaderboardStat();
	unsigned long GetbNotifyTicker();
	unsigned long GetbShowOnHUD();
	unsigned long GetbPrimaryStat();
	unsigned long GetbSkipReplication();
	unsigned long GetbCanMute();
	unsigned long GetbCountMultiplied();
	UnrealStringWrapper GetLabel();
	UnrealStringWrapper GetPluralLabel();
	UnrealStringWrapper GetDescription();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	float GetNextCooldownTime();
	std::string GetGroupName();
    std::string GetEventName();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};