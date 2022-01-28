#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ObjectWrapper.h"
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameSettingPlaylistWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(GameSettingPlaylistWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	std::string GetLocalizedName();
	std::string GetName();

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetTitle();
	UnrealStringWrapper GetDescription();
	int32_t GetPlayerCount();
	void SetPlayerCount(int32_t newPlayerCount);
	unsigned long GetbStandard();
	void SetbStandard(unsigned long newbStandard);
	unsigned long GetbRanked();
	void SetbRanked(unsigned long newbRanked);
	unsigned long GetbSolo();
	void SetbSolo(unsigned long newbSolo);
	unsigned long GetbNew();
	void SetbNew(unsigned long newbNew);
	unsigned long GetbApplyQuitPenalty();
	void SetbApplyQuitPenalty(unsigned long newbApplyQuitPenalty);
	unsigned long GetbAllowForfeit();
	void SetbAllowForfeit(unsigned long newbAllowForfeit);
	unsigned long GetbDisableRankedReconnect();
	void SetbDisableRankedReconnect(unsigned long newbDisableRankedReconnect);
	unsigned long GetbIgnoreAssignTeams();
	void SetbIgnoreAssignTeams(unsigned long newbIgnoreAssignTeams);
	unsigned long GetbKickOnMigrate();
	void SetbKickOnMigrate(unsigned long newbKickOnMigrate);
	unsigned long GetbAllowClubs();
	void SetbAllowClubs(unsigned long newbAllowClubs);
	unsigned long GetbPlayersVSBots();
	void SetbPlayersVSBots(unsigned long newbPlayersVSBots);
	int32_t GetPlaylistId();
	void SetPlaylistId(int32_t newPlaylistId);
	UnrealStringWrapper GetServerCommand();

	//AUTO-GENERATED FUNCTION PROXIES
	bool IsLanMatch();
	bool IsPrivateMatch();
	bool IsTournamentMatch();
	bool ShouldUpdateSkills();
	bool IsValidID(int32_t InPlaylistID);
	bool IsValid2();
	
private:
	PIMPL
};