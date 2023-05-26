#pragma once
#include "bakkesmod/wrappers/GameEvent/ReplayWrapper.h"
#include "bakkesmod/core/replay_structs.h"

class PriWrapper;

class BAKKESMOD_PLUGIN_IMPORT ReplaySoccarWrapper : public ReplayWrapper
{
public:
	CONSTRUCTORS(ReplaySoccarWrapper)

	_NODISCARD std::vector<ScoredGoal> GetGoals() const;
	_NODISCARD std::vector<Highlight> GetHighlights() const;
	_NODISCARD std::vector<ReplayPlayerStats> GetPlayerStats() const;


	//AUTO-GENERATED FROM FIELDS
	int GetTeamSize();
	void SetTeamSize(int newTeamSize);
	int GetUnfairTeamSize();
	void SetUnfairTeamSize(int newUnfairTeamSize);
	unsigned long GetbUnfairBots();
	void SetbUnfairBots(unsigned long newbUnfairBots);
	int GetPrimaryPlayerTeam();
	void SetPrimaryPlayerTeam(int newPrimaryPlayerTeam);
	int GetTeam0Score();
	void SetTeam0Score(int newTeam0Score);
	int GetTeam1Score();
	void SetTeam1Score(int newTeam1Score);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventPreExport();
	void RemoveTimelineKeyframe(int KeyframeIndex);
	void RecordUserEvent();
	void AddPlayer(PriWrapper PRI);

private:
	PIMPL
};
