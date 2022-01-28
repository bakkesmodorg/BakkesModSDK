#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/GameEventWrapper.h"
class PlayerControllerWrapper;
class CarWrapper;
class PriWrapper;
class TeamWrapper;

class BAKKESMOD_PLUGIN_IMPORT TeamGameEventWrapper : public GameEventWrapper {
public:
	CONSTRUCTORS(TeamGameEventWrapper)

	//AUTO-GENERATED FROM FIELDS
	ArrayWrapper<TeamWrapper> GetTeamArchetypes();
	ArrayWrapper<TeamWrapper> GetTeams();
	int32_t GetMaxTeamSize();
	void SetMaxTeamSize(int32_t newMaxTeamSize);
	int32_t GetNumBots();
	void SetNumBots(int32_t newNumBots);
	unsigned long GetbMuteOppositeTeams();
	void SetbMuteOppositeTeams(unsigned long newbMuteOppositeTeams);
	unsigned long GetbDisableMutingOtherTeam();
	void SetbDisableMutingOtherTeam(unsigned long newbDisableMutingOtherTeam);
	unsigned long GetbForfeit();
	void SetbForfeit(unsigned long newbForfeit);
	unsigned long GetbUnfairTeams();
	void SetbUnfairTeams(unsigned long newbUnfairTeams);
	unsigned long GetbAlwaysAutoSelectTeam();
	void SetbAlwaysAutoSelectTeam(unsigned long newbAlwaysAutoSelectTeam);

	//AUTO-GENERATED FUNCTION PROXIES
	void StartRematchVote();
	void CheckRematchVote();
	bool __GameEvent_Team_TA__AllTeamsHaveHumans(TeamWrapper Team);
	void UpdatePlayerShortcuts();
	void ClearTemporarySpawnSpots();
	bool ChooseTeam(int32_t TeamIndex, PlayerControllerWrapper Player);

	[[deprecated("Removed from Rocket League, defaults to false")]]
	bool CanChangeTeam();
	void OnPenaltyChanged();
	void OnTeamForfeited(TeamWrapper Team);
	void HandleTeamForfeit(TeamWrapper Team);
	void MuteOppositeTeams2(unsigned long bMute);
	void UpdateBotCount();
	bool FindBotReplacement(PriWrapper PRI);
	void EndGame();
	void ForceNoContest();
	void AddTemporarySpawnSpot(TeamWrapper Team, CarWrapper Car);
	void HandleSelectedLoadout(PriWrapper PlayerPRI);
	void DestroyTeams();
	void OnAllTeamsCreated();
	void AssignCustomTeamSettings();
	void OnMatchSettingsChanged();
	bool AllTeamsHaveHumans2();
	bool AllTeamsCreated2();
	void SetTeam(int32_t TeamNum, TeamWrapper NewTeam);
	void CreateTeams();
	void PreloadBots();
	void OnInit();
	void SetMaxTeamSize2(int32_t MaxSize);
	void UpdateMaxTeamSize();
	void SetUnfairTeams(unsigned long bUnfair);
	void InitBotSkill();
	void eventInitGame(std::string Options);
private:
	PIMPL
};