#pragma once

struct FScoredGoal;
struct FHighlight;
struct FReplayPlayerStats;

struct ScoredGoal
{
	ScoredGoal() = default;
	explicit ScoredGoal(const FScoredGoal& other);
	explicit operator FScoredGoal() const;

	int frame{};
	std::string player_name;
	int player_team{};
};


struct Highlight
{
	Highlight() = default;
	explicit Highlight(const FHighlight& other);
	explicit operator FHighlight() const;

	int frame;
	int car_name_index;
	int ball_name_index;
	int goal_actor_name_index;
};


struct ReplayPlayerStats
{
	ReplayPlayerStats() = default;
	explicit ReplayPlayerStats(const FReplayPlayerStats& other);
	explicit operator FReplayPlayerStats() const;

	std::string name;
	unsigned char platform{}; /*U_Types_Core_OnlinePlatform*/
	unsigned long long online_id{};
	int team{};
	int score{};
	int goals{};
	int assists{};
	int saves{};
	int shots{};
	bool is_bot{};
};