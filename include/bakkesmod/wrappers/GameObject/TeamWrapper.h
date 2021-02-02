#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/TeamInfoWrapper.h"
class UnrealStringWrapper;
class ActorWrapper;
class PriWrapper;
class TeamGameEventWrapper;
class WrapperStructs;

class BAKKESMOD_PLUGIN_IMPORT TeamWrapper : public TeamInfoWrapper {
public:
	CONSTRUCTORS(TeamWrapper)

	//AUTO-GENERATED FROM FIELDS
    LinearColor GetPrimaryColor();
    LinearColor GetSecondaryColor();
	LinearColor GetFontColor();
	void SetFontColor(LinearColor newFontColor);
	LinearColor GetColorBlindFontColor();
	void SetColorBlindFontColor(LinearColor newColorBlindFontColor);
	UnrealColor GetTeamControllerColor();
	void SetTeamControllerColor(UnrealColor newTeamControllerColor);
	UnrealColor GetTeamScoreStrobeColor();
	void SetTeamScoreStrobeColor(UnrealColor newTeamScoreStrobeColor);
	StructArrayWrapper<LinearColor> GetDefaultColorList();
	StructArrayWrapper<LinearColor> GetColorBlindColorList();
	StructArrayWrapper<LinearColor> GetCurrentColorList();
	TeamGameEventWrapper GetGameEvent();
	void SetGameEvent(TeamGameEventWrapper newGameEvent);
	ArrayWrapper<PriWrapper> GetMembers();
	UnrealStringWrapper GetCustomTeamName();
	UnrealStringWrapper GetSanitizedTeamName();
	unsigned long long GetClubID();
	void SetClubID(unsigned long long newClubID);
	unsigned long GetbForfeit();
	void SetbForfeit(unsigned long newbForfeit);

	//AUTO-GENERATED FUNCTION PROXIES
	bool __Team_TA__GetHumanPlayers(PriWrapper PRI);
	bool __Team_TA__GetHumanPrimaryPlayers(PriWrapper PRI);
	bool __Team_TA__GetNumOfMembersThatCanStartForfeit(PriWrapper P);
	void __Team_TA__EnableAllMembersStartVoteToForfeit(PriWrapper Member);
	void OnClubColorsChanged();
	void Forfeit2();
	void EnableAllMembersStartVoteToForfeit2();
	void EnableAllMembersStartVoteToForfeitIfNecessary();
	void VoteToForfeit22(PriWrapper PRI);
	void NotifyKismetTeamColorChanged();
	void UpdateColors();
	void SetLogo(int LogoID, unsigned long bSwapColors);
	void HandleTeamNameSanitized(std::string Original, std::string Sanitized);
	void SetClubID2(unsigned long long InClubID);
	void SetCustomTeamName(std::string NewName);
	void SetDefaultColors();
	bool IsSingleParty();
	PriWrapper GetTeamMemberNamed(std::string PlayerName);
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