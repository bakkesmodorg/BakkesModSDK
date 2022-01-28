#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/ReplayWrapper.h"
class PriWrapper;

class BAKKESMOD_PLUGIN_IMPORT ReplaySoccarWrapper : public ReplayWrapper {
public:
	CONSTRUCTORS(ReplaySoccarWrapper)

	//AUTO-GENERATED FROM FIELDS
	int32_t GetTeamSize();
	void SetTeamSize(int32_t newTeamSize);
	int32_t GetUnfairTeamSize();
	void SetUnfairTeamSize(int32_t newUnfairTeamSize);
	unsigned long GetbUnfairBots();
	void SetbUnfairBots(unsigned long newbUnfairBots);
	int32_t GetPrimaryPlayerTeam();
	void SetPrimaryPlayerTeam(int32_t newPrimaryPlayerTeam);
	int32_t GetTeam0Score();
	void SetTeam0Score(int32_t newTeam0Score);
	int32_t GetTeam1Score();
	void SetTeam1Score(int32_t newTeam1Score);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventPreExport();
	void RemoveTimelineKeyframe(int32_t KeyframeIndex);
	void RecordUserEvent();
	void AddPlayer(PriWrapper PRI);
private:
	PIMPL
};