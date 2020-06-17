#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/TeamGameEventWrapper.h"
class PlayerControllerWrapper;
class CarWrapper;
class ReplayDirectorWrapper;
class TeamWrapper;
class ActorWrapper;
class PriWrapper;
class BallWrapper;
class GoalWrapper;

class BAKKESMOD_PLUGIN_IMPORT ServerWrapper : public TeamGameEventWrapper {
public:
	CONSTRUCTORS(ServerWrapper)

	//BEGIN SELF IMPLEMENTED
	BallWrapper GetBall();
	void SpawnCar(int carBody, std::string name);
	void SpawnBot(int carBody, std::string name);
	BallWrapper SpawnBall(const Vector position, bool wake, bool spawnCannon);
	bool HasAuthority();
	GETSETH(float, GameSpeed)
	GETSETH(float, SecondsElapsed)	
		
		CarWrapper GetGameCar();
	bool IsBallMovingTowardsGoal(int goalNo, BallWrapper bw);
	bool IsInGoal(Vector vec);
	void DisableGoalReset();
	void EnableGoalReset();
	//void SpawnCar(int body = 0);
	//Speed from 0 to 2000 pls
	Vector GenerateShot(Vector startPos, Vector destination, float speed);
	Vector GenerateGoalAimLocation(int goalNumber, Vector currentBallLocation);
	Vector GetGoalExtent(int goalNumber = 0);
	Vector GetGoalLocation(int goalNumber = 0);//END SELF IMPLEMENTED
		//END SELF IMPLEMENTED

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
	int GetWaitTimeRemaining();
	void SetWaitTimeRemaining(int newWaitTimeRemaining);
	float GetTotalGameTimePlayed();
	void SetTotalGameTimePlayed(float newTotalGameTimePlayed);
	float GetOvertimeTimePlayed();
	void SetOvertimeTimePlayed(float newOvertimeTimePlayed);
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
	PlayerControllerWrapper GetPauser();
	void SetPauser(PlayerControllerWrapper newPauser);

	//AUTO-GENERATED FUNCTION PROXIES
	int GetPlayerCarCount();
	void ReplicateSkillTiers();
	void RemoveTeamSelection();
	void CheckStart();
	void StartLobbyTimer();
	void HandleCountdownTick();
	void CheckForCountdownAction();
	void LobbyCountdownTick();
	bool CanSpawnBots();
	void StartRound();
	void EndRound();
	void SetBallEventListeners(BallWrapper Ball, unsigned long bListen);
	bool CanAwardPoints();
	void HandleCarTouch(BallWrapper Ball, CarWrapper HitCar, unsigned char HitType);
	void SetBallHasBeenHit2();
	int DetermineScoreTouchIndex(BallWrapper Ball, GoalWrapper Goal);
	int DetermineAssistTouchIndex(BallWrapper Ball, int ScoreIdx);
	void UpdateTotalGameTimePlayed(float DeltaTime);
	void UpdateGameTime(float DeltaTime);
	bool CanUpdateGameTime();
	void WaitForBallOnGround();
	bool BallHitGround(Vector& HitNorm);
	void HandleBallHitGround(BallWrapper Ball, Vector& HitLoc, Vector& HitNorm);
	void HandleBallHitGroundTimeout();
	void StartReplay();
	void HandleReplayFinished(ReplayDirectorWrapper InReplay);
	void GotoPodiumSpotlight();
	void UpdateSpotlight();
	void SpawnPodiumCars();
	bool CanEnableCarPodiumMovement();
	void FinishEvent();
	bool __GameEvent_Soccar_TA__UpdateTeamScores(TeamWrapper T);
	void __GameEvent_Soccar_TA__SubmitMatchComplete(PriWrapper PRI);
	void __GameEvent_Soccar_TA__CheckStart(TeamWrapper T);
	void __GameEvent_Soccar_TA__EndState(TeamWrapper T);
	void __ReplicatedServerPerformanceState__ChangeNotifyFunc();
	void __bClubMatch__ChangeNotifyFunc();
	void __bShowIntroScene__ChangeNotifyFunc();
	void __WaitTimeRemaining__ChangeNotifyFunc();
	void CheckJoinInProgress(PriWrapper PRI);
	bool AllowDynamicCrowd();
	void AddBallTrajectory(BallWrapper InBall);
	bool ShowScorerGoalMessage();
	bool CanUseBallCam();
	bool DisableStatXP();
	void SetDisableGoalDelay(unsigned long bInDisableGoalDelay);
	void ForceMatchStart();
	void RemoveLocalPlayer(PlayerControllerWrapper Player);
	void AddLocalPlayer(PlayerControllerWrapper Player);
	void DestroyGoalIndicators(PlayerControllerWrapper Player);
	void CreateGoalIndicators(PlayerControllerWrapper Player);
	void BeginHighlightsReplay();
	bool ShouldCountUp();
	bool ShouldAllowVoteToForfeit();
	bool ShouldHaveLeaveMatchPenalty();
	void SetPaused(PlayerControllerWrapper InPauser, unsigned long bInPaused);
	bool ShouldCountdownResumeFromPause();
	void SetScoreAndTime(PlayerControllerWrapper PC, int NewScoreTeam0, int NewScoreTeam1, int InGameTimeRemaining, unsigned long bInOvertime, unsigned long bRestartRound);
	void SaveLocalPlayerStats();
	bool ShouldPlayReplay();
	bool ShouldRecordReplay();
	void OnBallHasBeenHit();
	BallWrapper SpawnBall2(Vector& SpawnLoc, unsigned long bWake, unsigned long bSpawnCannon, std::string BallArch);
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
	void SetTotalGameBalls2(int TotalBalls);
	void RecordRecentPlayers();
	void UpdateStats();
	void NotifyKismetOfCurrentTime();
	bool EnoughTimePassedToForfeit();
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
	void SubmitMatch2();
	void SubmitMatchComplete2();
	void OnMatchEnded();
	bool ShouldDoPodiumSpotlight();
	void EndGame();
	void UpdateTeamScores2();
	void StartNewGame();
	void ResetGame();
	void ClearReplicatedStatEvent();
	void eventDestroyed();
	void InitBotDetection();
	void InitCrowdManager();
	void InitField();
	void InitGameObserver();
	void OnInit();
	void InitMutators();
	void OnClubMatch();
	bool CanInitClubMatch();
	void AssignCustomTeamSettings();
	void InitGame2(std::string Options);
	std::string GetMatchGUID();
	void SetMatchGUID(std::string s);
	void EventGameWinnerSet(ServerWrapper GameEvent);
	void EventGoalScored(ServerWrapper GameEvent, BallWrapper Ball, GoalWrapper Goal, int ScoreIndex, int AssistIdx);
private:
	PIMPL
};