#pragma once
#include "./Engine/ObjectWrapper.h"
#include "wrapperstructs.h"
class BAKKESMOD_PLUGIN_IMPORT MMRWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(MMRWrapper);
	bool IsSyncing(SteamID playerID);
	bool IsSynced(SteamID playerID, int playlistID);
	bool IsRanked(int playlistID);
	SkillRating GetPlayerSkillRating(SteamID playerID, int playlistID);
	SkillRank GetPlayerRank(SteamID playerID, int playlistID);
	float GetPlayerMMR(SteamID playerID, int playlistID);
	float CalculateMMR(SkillRating sr, bool disregardPlacements);
	int GetCurrentPlaylist();
private:
	PIMPL
};

