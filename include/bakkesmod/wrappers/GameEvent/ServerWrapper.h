#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/TeamGameEventWrapper.h"
class PriWrapper;
class GoalWrapper;
class ReplayDirectorWrapper;
class ActorWrapper;
class BallWrapper;
class TeamWrapper;
class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT ServerWrapper : public TeamGameEventWrapper {
public:
	CONSTRUCTORS(ServerWrapper)

	//BEGIN SELF IMPLEMENTED
	BallWrapper GetBall();
	void SpawnCar(int carBody, string name);
	BallWrapper SpawnBall(Vector position, bool wake, bool spawnCannon);
	bool HasAuthority();
	int GetCurrentReplayFrame();
	GETSETH(float, GameSpeed)
		GETSETH(float, SecondsElapsed)	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	CarWrapper GetTestCarArchetype();
	void SetTestCarArchetype(CarWrapper newTestCarArchetype);
	BallWrapper GetBallArchetype();
	void SetBallArchetype(BallWrapper newBallArchetype);
	ActorWrapper GetBallSpawnPoint();
	void SetBallSpawnPoint(ActorWrapper newBallSpawnPoint);
	int GetSeriesLength();
	void SetSeriesLength(int newSeriesLength);
	int GetGameTime();
	void SetGameTime(int newGameTime);
	int GetWarmupTime();
	void SetWarmupTime(int newWarmupTime);
	int GetMaxScore();
	void SetMaxScore(int newMaxScore);
	int GetAutoBalanceDifference();
	void SetAutoBalanceDifference(int newAutoBalanceDifference);
	int GetLastTrialTime();
	void SetLastTrialTime(int newLastTrialTime);
	float GetScoreSlomoTime();
	void SetScoreSlomoTime(float newScoreSlomoTime);
	float GetGameTimeRemaining();
	void SetGameTimeRemaining(float newGameTimeRemaining);
	int GetSecondsRemaining();
	void SetSecondsRemaining(int newSecondsRemaining);
	float GetTotalGameTimePlayed();
	void SetTotalGameTimePlayed(float newTotalGameTimePlayed);
	unsigned long GetbRoundActive();
	void SetbRoundActive(unsigned long newbRoundActive);
	unsigned long GetbPlayReplays();
	void SetbPlayReplays(unsigned long newbPlayReplays);
	unsigned long GetbBallHasBeenHit();
	void SetbBallHasBeenHit(unsigned long newbBallHasBeenHit);
	unsigned long GetbOverTime();
	void SetbOverTime(unsigned long newbOverTime);
	unsigned long GetbUnlimitedTime();
	void SetbUnlimitedTime(unsigned long newbUnlimitedTime);
	unsigned long GetbKickOnTrialEnd();
	void SetbKickOnTrialEnd(unsigned long newbKickOnTrialEnd);
	unsigned long GetbNoContest();
	void SetbNoContest(unsigned long newbNoContest);
	unsigned long GetbDisableGoalDelay();
	void SetbDisableGoalDelay(unsigned long newbDisableGoalDelay);
	unsigned long GetbShowNoScorerGoalMessage();
	void SetbShowNoScorerGoalMessage(unsigned long newbShowNoScorerGoalMessage);
	unsigned long GetbMatchEnded();
	void SetbMatchEnded(unsigned long newbMatchEnded);
	unsigned long GetbShowIntroScene();
	void SetbShowIntroScene(unsigned long newbShowIntroScene);
	unsigned long GetbClubMatch();
	void SetbClubMatch(unsigned long newbClubMatch);
	int GetNextSpawnIndex();
	void SetNextSpawnIndex(int newNextSpawnIndex);
	ReplayDirectorWrapper GetReplayDirectorArchetype();
	void SetReplayDirectorArchetype(ReplayDirectorWrapper newReplayDirectorArchetype);
	ReplayDirectorWrapper GetReplayDirector();
	void SetReplayDirector(ReplayDirectorWrapper newReplayDirector);
	ArrayWrapper<BallWrapper> GetGameBalls();
	int GetTotalGameBalls();
	void SetTotalGameBalls(int newTotalGameBalls);
	float GetPostGoalTime();
	void SetPostGoalTime(float newPostGoalTime);
	ArrayWrapper<GoalWrapper> GetGoals();
	int GetSecondsRemainingCountdown();
	void SetSecondsRemainingCountdown(int newSecondsRemainingCountdown);
	Vector GetFieldCenter();
	void SetFieldCenter(Vector newFieldCenter);
	TeamWrapper GetGameWinner();
	void SetGameWinner(TeamWrapper newGameWinner);
	TeamWrapper GetMatchWinner();
	void SetMatchWinner(TeamWrapper newMatchWinner);
	PriWrapper GetMVP();
	void SetMVP(PriWrapper newMVP);
	PriWrapper GetFastestGoalPlayer();
	void SetFastestGoalPlayer(PriWrapper newFastestGoalPlayer);
	PriWrapper GetSlowestGoalPlayer();
	void SetSlowestGoalPlayer(PriWrapper newSlowestGoalPlayer);
	PriWrapper GetFurthestGoalPlayer();
	void SetFurthestGoalPlayer(PriWrapper newFurthestGoalPlayer);
	float GetFastestGoalSpeed();
	void SetFastestGoalSpeed(float newFastestGoalSpeed);
	float GetSlowestGoalSpeed();
	void SetSlowestGoalSpeed(float newSlowestGoalSpeed);
	float GetFurthestGoal();
	void SetFurthestGoal(float newFurthestGoal);
	unsigned char GetReplicatedScoredOnTeam();
	void SetReplicatedScoredOnTeam(unsigned char newReplicatedScoredOnTeam);
	unsigned char GetReplicatedServerPerformanceState();
	void SetReplicatedServerPerformanceState(unsigned char newReplicatedServerPerformanceState);
	int GetRoundNum();
	void SetRoundNum(int newRoundNum);
	float GetKickIdleReplayOffset();
	void SetKickIdleReplayOffset(float newKickIdleReplayOffset);
	float GetAssistMaxTime();
	void SetAssistMaxTime(float newAssistMaxTime);
	float GetBallHasBeenHitStartDelay();
	void SetBallHasBeenHitStartDelay(float newBallHasBeenHitStartDelay);
	float GetPodiumDelay();
	void SetPodiumDelay(float newPodiumDelay);
	float GetPodiumTime();
	void SetPodiumTime(float newPodiumTime);
	int GetLobbyEndCountdown();
	void SetLobbyEndCountdown(int newLobbyEndCountdown);
	int GetLobbyCountdown();
	void SetLobbyCountdown(int newLobbyCountdown);
	float GetLobbyTime();
	void SetLobbyTime(float newLobbyTime);
	int GetLobbySpawnRestartTime();
	void SetLobbySpawnRestartTime(int newLobbySpawnRestartTime);

	//AUTO-GENERATED FUNCTION PROXIES
	bool __GameEvent_Soccar_TA__UpdateTeamScores(TeamWrapper T);
	void __GameEvent_Soccar_TA__CheckStart(TeamWrapper T);
	void __ReplicatedServerPerformanceState__ChangeNotifyFunc();
	void __bShowIntroScene__ChangeNotifyFunc();
	bool AllowDynamicCrowd();
	void AddBallTrajectory(BallWrapper InBall);
	bool ShowScorerGoalMessage();
	bool CanUseBallCam();
	bool DisableStatXP();
	void SetDisableGoalDelay(unsigned long bInDisableGoalDelay);
	void ForceMatchStart();
	void BeginHighlightsReplay();
	bool ShouldAllowVoteToForfeit();
	bool ShouldHaveLeaveMatchPenalty();
	bool ShouldCountdownResumeFromPause();
	void SaveLocalPlayerStats();
	bool ShouldPlayReplay();
	bool ShouldRecordReplay();
	void OnBallHasBeenHit();
	int GetTotalScore();
	void HandleCarSet(PriWrapper InPRI);
	void RemovePRI(PriWrapper PRI);
	void AddPRI(PriWrapper PRI);
	void OnMatchWinnerSet();
	void OnGameWinnerSet();
	int MVPSort(PriWrapper A, PriWrapper B);
	void HandleHitGoal(BallWrapper Ball, GoalWrapper Goal);
	void ClearReplicatedScoredOnTeam();
	void TriggerScoreChangedEvent();
	void HandleScoreUpdated(TeamWrapper Team);
	void OnAllTeamsCreated();
	void TriggerGoalScoreEvent(int TeamScoredOn, CarWrapper Scorer);
	bool CanAwardAchievements();
	bool AllowScoreboard();
	void SetTotalGameBalls2(int TotalBalls);
	void RecordRecentPlayers();
	void UpdateStats();
	void NotifyKismetOfCurrentTime();
	void OnGameTimeUpdated();
	void OnOvertimeUpdated();
	void ForceOvertime();
	void StartOvertime();
	bool OnMyHalf(Vector& TestLocation, unsigned char TeamNum);
	TeamWrapper GetWinningTeam();
	void ResetPickups();
	void ResetPlayers();
	void OnBallSpawned(BallWrapper NewBall);
	void ResetBalls();
	void DestroyCars();
	void FreezePawns();
	void DestroyBalls();
	void RemoveGameBall(BallWrapper Ball);
	void AddGameBall(BallWrapper Ball);
	void StartNewRound();
	void CheckForAutoBalance();
	bool HasWinner();
	void SubmitSkillMatch();
	void OnMatchEnded();
	bool ShouldDoPodiumSpotlight();
	void EndGame();
	void UpdateTeamScores2();
	void StartNewGame();
	void ResetGame();
	void ClearReplicatedStatEvent();
	void eventDestroyed();
	void InitCrowdManager();
	void InitField();
	void InitGameObserver();
	void InitMatchRecorder();
	void OnInit();
	void InitMutators();
	void AssignCustomTeamSettings();
	void EventGameWinnerSet(ServerWrapper GameEvent);
	void EventGoalScored(ServerWrapper GameEvent, BallWrapper Ball, GoalWrapper Goal, int ScoreIndex, int AssistIdx);
private:
	PIMPL
};