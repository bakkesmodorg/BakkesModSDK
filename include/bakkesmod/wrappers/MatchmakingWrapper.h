﻿#pragma once
#include <string>
#include "Engine/ObjectWrapper.h"

enum class Region
{
    USE = 0,	// US-East
    EU = 1,		// Europe
    USW = 2,	// US-West
    ASC = 3,	// Asia-SE Mainland
    ASM = 4,	// Asia-SE Maritime
    JPN = 5,	// Asia-East
    ME = 6,		// Middle-East
    OCE = 7,	// Oceania
    SAF = 8,	// South Africa
    SAM = 9,	// South America
    IND = 10	// India
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
	BoomerBall = 41,
	GodBallDoubles = 43,
	SpecialSnowDay = 44,
	Football = 46,
	Cubic = 47,
	TacticalRumble = 48,
	SpringLoaded = 49,
	SpeedDemon = 50,
	RumbleBM = 52
};

struct ClubColorSet
{
    uint8_t TeamColorID = 0;
    uint8_t CustomColorID = 0;
    bool bTeamColorSet = false;
    bool bCustomColorSet = false;
};

struct CustomMatchTeamSettings
{
    std::string Name;
    ClubColorSet Colors;
    int32_t GameScore = 0;
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
    int32_t GameMode = 0; // 0 = soccar, 1 = hoops, 2 = snowday, 3 = rumble, 5 = dropshot, 6 = heatseeker (might change)
    int32_t MaxPlayerCount = 8;
    bool bPartyMembersOnly = false;
    bool bClubServer;
};

class BAKKESMOD_PLUGIN_IMPORT MatchmakingWrapper: public ObjectWrapper
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
    void CreatePrivateMatch(Region region, const CustomMatchSettings& match_settings);
	void JoinPrivateMatch(const std::string& server_name, const std::string& server_password = "");

    // LAN stuff
    void CreateLanMatch(Region region, const CustomMatchSettings& match_settings) const;
    void JoinLanMatch(const std::string& server_id, const std::string& password) const;

	// Season stuff
    // If no season end date has been revealed yet, these functions will return either 0 or -1.
    int32_t SeasonEndDays();
    int32_t SeasonEndHours();
    int32_t SeasonEndMinutes();
    int32_t GetSeasonTimeRemaining();
    int32_t GetSeasonEndTimeSeconds();

    bool HasSeasonEnded();
    int32_t GetTotalPopulation();

    _NODISCARD int32_t GetTotalPlayersOnline() const;
	_NODISCARD int32_t GetPlayerCount(PlaylistIds playlist) const;

	//misc
    static std::string GetRegionID(Region region); // ID Example: USE
    static std::string GetRegionLabel(Region region); // Label Example: US-East

private:
	PIMPL
};