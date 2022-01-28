#pragma once
#include "./Engine/ObjectWrapper.h"
#include "wrapperstructs.h"
#include "UniqueIDWrapper.h"

class MMRWrapper;

struct BAKKESMOD_PLUGIN_IMPORT MMRNotifierToken
{
	friend class MMRWrapper;
	// The deconstructor deregisters your plugin for MMR notifications.
	~MMRNotifierToken();
	
	// Copying would break the deconstruction logic. 
	MMRNotifierToken(const MMRNotifierToken& other) = delete;
	MMRNotifierToken& operator=(const MMRNotifierToken& other) = delete;
	// Move is OK
	MMRNotifierToken(MMRNotifierToken&& other) noexcept = default;
	MMRNotifierToken& operator=(MMRNotifierToken&& other) noexcept = default;
	

private:
	explicit MMRNotifierToken(unsigned long long t);
	// Do we need pimpl here?
	uint64_t token;
};

class BAKKESMOD_PLUGIN_IMPORT MMRWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(MMRWrapper);
	bool IsSyncing(UniqueIDWrapper playerID);
	bool IsSyncing(SteamID playerID);
	bool IsSynced(UniqueIDWrapper playerID, int32_t playlistID);
	bool IsSynced(SteamID playerID, int32_t playlistID);
	bool IsRanked(int32_t playlistID);

	SkillRating GetPlayerSkillRating(UniqueIDWrapper playerID, int32_t playlistID);
	SkillRank GetPlayerRank(UniqueIDWrapper playerID, int32_t playlistID);
	float GetPlayerMMR(UniqueIDWrapper playerID, int32_t playlistID);

	SkillRating GetPlayerSkillRating(SteamID playerID, int32_t playlistID);
	SkillRank GetPlayerRank(SteamID playerID, int32_t playlistID);
	float GetPlayerMMR(SteamID playerID, int32_t playlistID);
	float CalculateMMR(SkillRating sr, bool disregardPlacements);
	int32_t GetCurrentPlaylist();

	/// <summary>
	/// Subscribe to MMR updates. The callback will receive a ID wrapper for the player that the MMR update is relevant for.
	/// </summary>
	/// <param name="notification_callback">The callback that will be called for each mmr update</param>
	/// <returns>a token whos lifetime controls your callback registration. When the token is destroyed, so is your registration. </returns>
	std::unique_ptr<MMRNotifierToken> RegisterMMRNotifier(std::function<void(UniqueIDWrapper id)>);


private:
	PIMPL
};

