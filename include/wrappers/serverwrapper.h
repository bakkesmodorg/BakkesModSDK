#pragma once
#include "gameeventwrapper.h"
#include "teamwrapper.h"
#include "arraywrapper.h"
#include "carwrapper.h"
class ServerWrapper;
typedef void (*tick_func)(ControllerInput*, CarWrapper, BallWrapper, ServerWrapper);

class BAKKESMOD_PLUGIN_IMPORT ServerWrapper : public GameEventWrapper
{
public:
	CONSTRUCTORS(ServerWrapper)

	//AUTO GENERATED
	GETSETH(int, TimeRemaining)
	GETSETH(int, PodiumTime)
	GETSETH(float, GameSpeed)
	GETSETH(float, SecondsElapsed)
	GETSETH(int, GameTime)
	GETSETH(int, MaxScore)
	GETSETH(int, TotalGameTimePlayed)
	GETSETH(int, GamesPlayed)
	GETSETH(bool, PlayReplays)
	GETSETH(bool, BallHasBeenHit)
	GETSETH(bool, OverTime)
	GETSETH(bool, UnlimitedTime)
	GETSETH(bool, DisableGoalDelay)
	GETSETH(bool, MatchEnded)
	GETSETH(bool, TotalGameBalls)
	GETSETH(float, PostGoalTime)
	GETSETH(int, SecondsRemainingCountdown)
	GETSETH(float, AssistMaxTime)
	GETSETH(float, BallHasBeenHitStartDelay)
	GETSETH(float, LobbyTime)
	GETSETH(int, LobbyCountdown)
	GETSETH(int, LobbySpawnRestartTime)
	GETSETH(int, CountdownTime)

	//SELF IMPLEMENTED
	TeamWrapper GetTeam(int teamNum);
	ArrayWrapper<PriWrapper> GetPRIs();
	//ArrayWrapper<TeamWrapper> GetTeams();
	ArrayWrapper<CarWrapper> GetPlayers();
	Vector GetGoalLocation(int goalNumber = 0);
	int GetScoredOnTeam();
	BallWrapper SpawnBall(Vector position, bool wake, bool spawnCannon=false);
	ArrayWrapper<BallWrapper> GetBalls();
	bool RemoveBall(BallWrapper ball);
	void MoveToGround(ActorWrapper ac, float heightCheck = 4096.0f);
	void SpawnBotWithAI(tick_func tf);
	ControllerInput GetUserInput();
	void StartCountdown();
	void ResetBalls();
	void SetGameStateTime(int time);
	void SetAllDriving(bool allDriving);

private:
	PIMPL
};