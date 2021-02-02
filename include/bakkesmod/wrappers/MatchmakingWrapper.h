#pragma once
#include <string>
#include "Engine/ObjectWrapper.h"

enum class Region
{
    USE = 0,    // US-East
    EU = 1,     // Europe
    USW = 2,    // US-West
    ASC = 3,    // Asia-SE Mainland
    ASM = 4,    // Asia-SE Maritime
    JPN = 5,    // Asia-East
    ME = 6,     // Middle-East
    OCE = 7,    // Oceania
    SAF = 8,    // South Africa
    SAM = 9,     // South America
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
    EXTRAS_RUMBLE = 12,
    EXTRAS_DROPSHOT = 13,
    EXTRAS_HOOPS = 14,
    EXTRAS_SNOWDAY = 15
};

enum class PlaylistCategory
{
    CASUAL = 0,
    RANKED = 1,
    EXTRAS = 2
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
    int GameMode = 0; // 0 = soccar, 1 = hoops, 2 = snowday, 3 = rumble, 5 = dropshot, 6 = heatseeker (might change)
    int MaxPlayerCount = 8;
    bool bPartyMembersOnly = false;
    bool bClubServer;
};

class BAKKESMOD_PLUGIN_IMPORT MatchmakingWrapper: public ObjectWrapper
{
public:
    CONSTRUCTORS(MatchmakingWrapper)

	[[nodiscard]] bool IsNull() const;
	explicit operator bool() const;

	//Matchmaking queue stuff
    bool IsSearching();
    int GetActiveViewTab();

    void SetRegionSelection(Region region, bool bSelected);
    void SetPlaylistSelection(Playlist playlist, bool bSelected);
    void StartMatchmaking(PlaylistCategory playlist_category);
    void CancelMatchmaking();

	// Private match stuff
    void CreatePrivateMatch(Region region, const CustomMatchSettings& match_settings);
	void JoinPrivateMatch(const std::string& server_name, const std::string& server_password = "");

	// Season stuff
    // If no season end date has been revealed yet, these functions will return either 0 or -1.
    int SeasonEndDays();
    int SeasonEndHours();
    int SeasonEndMinutes();
    int GetSeasonTimeRemaining();
    int GetSeasonEndTimeSeconds();

    bool HasSeasonEnded();
    int GetTotalPopulation();

	//misc
    static std::string GetRegionID(Region region); // ID Example: USE
    static std::string GetRegionLabel(Region region); // Label Example: US-East

private:
	PIMPL
};