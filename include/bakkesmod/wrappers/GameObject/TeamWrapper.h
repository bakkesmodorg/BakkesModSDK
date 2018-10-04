#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"
class UnrealStringWrapper;
class PriWrapper;
class TeamGameEventWrapper;
class WrapperStructs;

class BAKKESMOD_PLUGIN_IMPORT TeamWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(TeamWrapper)

	//AUTO-GENERATED FROM FIELDS
	LinearColor GetFontColor();
	void SetFontColor(LinearColor newFontColor);
	LinearColor GetColorBlindFontColor();
	void SetColorBlindFontColor(LinearColor newColorBlindFontColor);
	StructArrayWrapper<LinearColor> GetDefaultColorList();
	StructArrayWrapper<LinearColor> GetColorBlindColorList();
	StructArrayWrapper<LinearColor> GetCurrentColorList();
	TeamGameEventWrapper GetGameEvent();
	void SetGameEvent(TeamGameEventWrapper newGameEvent);
	ArrayWrapper<PriWrapper> GetMembers();
	UnrealStringWrapper GetCustomTeamName();
	UnrealStringWrapper GetSanitizedTeamName();
	unsigned long GetbForfeit();
	void SetbForfeit(unsigned long newbForfeit);

	//AUTO-GENERATED FUNCTION PROXIES
	void OnClubColorsChanged();
	void Forfeit2();
	void VoteToForfeit(PriWrapper PRI);
	bool IsColorBlind();
	void NotifyKismetTeamColorChanged();
	void UpdateColors();
	void SetLogo(int LogoID, unsigned long bSwapColors);
	void SetDefaultColors();
	int GetNumBots();
	int GetNumHumans();
	void OnScoreUpdated();
	void ResetScore();
	void RemovePoints(int Points);
	void SetScore(int Points);
	void ScorePoint(int AdditionalScore);
	void MuteOtherTeam(TeamWrapper OtherTeam, unsigned long bMute);
	void ClearTemporarySpawnSpots();
	void ExpireTemporarySpawnSpots();
	void AddTemporarySpawnSpot(ActorWrapper AtActor);
	void OnGameEventSet();
	void SetGameEvent2(TeamGameEventWrapper InGameEvent);
private:
	PIMPL
};