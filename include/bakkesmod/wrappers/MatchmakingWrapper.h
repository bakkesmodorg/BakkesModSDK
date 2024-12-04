#pragma once
#include <string>
#include "Engine/ObjectWrapper.h"

enum class Region
{
	// US-East
	USE = 0,
	// Europe
	EU = 1,
	// US-West
	USW = 2,
	// Asia-SE Mainland
	ASC = 3,
	// Asia-SE Maritime
	ASM = 4,
	// Asia-East
	JPN = 5,
	// Middle-East
	ME = 6,
	// Oceania
	OCE = 7,
	// South Africa
	SAF = 8,
	// South America
	SAM = 9,
	// India
	IND = 10
};

enum class Playlist
{
	CASUAL_STANDARD = 0,
	CASUAL_DOUBLES = 1,
	CASUAL_DUELS = 2,
	CASUAL_CHAOS = 3,
	RANKED_STANDARD = 4,
	RANKED_DOUBLES = 5,
	RANKED_DUELS = 6,
	AUTO_TOURNAMENT = 12,
	EXTRAS_RUMBLE = 13,
	EXTRAS_DROPSHOT = 14,
	EXTRAS_HOOPS = 15,
	EXTRAS_SNOWDAY = 16
};

enum class PlaylistCategory
{
	CASUAL = 0,
	RANKED = 1,
	EXTRAS = 2
};

enum class PlaylistIds
{
	Unknown = -1337,
	Casual = 0,
	Duel = 1,
	Doubles = 2,
	Standard = 3,
	Chaos = 4,
	PrivateMatch = 6,
	Season = 7,
	OfflineSplitscreen = 8,
	Training = 9,
	RankedSoloDuel = 10,
	RankedTeamDoubles = 11,
	RankedStandard = 13,
	SnowDayPromotion = 15,
	Experimental = 16,
	BasketballDoubles = 17,
	Rumble = 18,
	Workshop = 19,
	UGCTrainingEditor = 20,
	UGCTraining = 21,
	Tournament = 22,
	Breakout = 23,
	TenthAnniversary = 25,
	FaceIt = 26,
	RankedBasketballDoubles = 27,
	RankedRumble = 28,
	RankedBreakout = 29,
	RankedSnowDay = 30,
	HauntedBall = 31,
	BeachBall = 32,
	Rugby = 33,
	AutoTournament = 34,
	RocketLabs = 35,
	RumShot = 37,
	GodBall = 38,
	CoopVsAI = 40,
	BoomerBall = 41,
	GodBallDoubles = 43,
	SpecialSnowDay = 44,
	Football = 46,
	Cubic = 47,
	TacticalRumble = 48,
	SpringLoaded = 49,
	SpeedDemon = 50,
	RumbleBM = 52,
	Knockout = 54,
	Thirdwheel = 55,
	MagnusFutball = 62
};

struct ClubColorSet
{
	unsigned char TeamColorID = 0;
	unsigned char CustomColorID = 0;
	bool bTeamColorSet = false;
	bool bCustomColorSet = false;
};

struct CustomMatchTeamSettings
{
	std::string Name;
	ClubColorSet Colors;
	int GameScore = 0;
};

struct CustomMatchSettings
{
	//  GameTags are the mutators. They should be comma separated (Launch a game manually and check your launch log for potential mutator names - or ask in #programming )
	std::string GameTags;
	std::string MapName;
	std::string ServerName;
	std::string Password;
	CustomMatchTeamSettings BlueTeamSettings;
	CustomMatchTeamSettings OrangeTeamSettings;
	int GameMode = 0; // 0 = soccar, 1 = hoops, 2 = snowday, 3 = rumble, 5 = dropshot, 6 = heatseeker, 7 = gridiron, 8 = knockout (might change)
	int MaxPlayerCount = 8;
	bool bPartyMembersOnly = false;
	bool bClubServer;
};

class BAKKESMOD_PLUGIN_IMPORT MatchmakingWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(MatchmakingWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//Matchmaking queue stuff
	bool IsSearching();
	int GetActiveViewTab();

	void SetRegionSelection(Region region, bool bSelected);
	void SetPlaylistSelection(Playlist playlist, bool bSelected);
	void SetViewTab(PlaylistCategory playlist_category);
	void StartMatchmaking(PlaylistCategory playlist_category);
	void CancelMatchmaking();

	// Private match stuff
	void CreatePrivateMatch(Region region, int playlistID, const CustomMatchSettings& match_settings);
	/**
	 * \brief Updates the settings of a private match lobby
	 * \param match_settings The lobby settings
	 * \return returns true if updating is successful
	 */
	[[nodiscard]] bool UpdatePrivateMatch(const CustomMatchSettings& match_settings) const;
	void JoinPrivateMatch(const std::string& server_name, const std::string& server_password = "");

	// LAN stuff
	void CreateLanMatch(Region region, const CustomMatchSettings& match_settings) const;
	void JoinLanMatch(const std::string& server_id, const std::string& password) const;

	// Season stuff
	// If no season end date has been revealed yet, these functions will return either 0 or -1.
	int SeasonEndDays();
	int SeasonEndHours();
	int SeasonEndMinutes();
	int GetSeasonTimeRemaining();
	int GetSeasonEndTimeSeconds();

	bool HasSeasonEnded();
	int GetTotalPopulation();

	_NODISCARD int GetTotalPlayersOnline() const;
	_NODISCARD int GetPlayerCount(PlaylistIds playlist) const;


	//misc
	static std::string GetRegionID(Region region); // ID Example: USE
	static std::string GetRegionLabel(Region region); // Label Example: US-East

private:
	PIMPL
};
