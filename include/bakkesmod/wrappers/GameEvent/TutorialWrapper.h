#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/ServerWrapper.h"
class PlayerControllerWrapper;
class UnrealStringWrapper;
class CarWrapper;
class GameEventWrapper;
class BallWrapper;
class GoalWrapper;
class TeamWrapper;

class BAKKESMOD_PLUGIN_IMPORT TutorialWrapper : public ServerWrapper {
public:
	CONSTRUCTORS(TutorialWrapper)

	//BEGIN SELF IMPLEMENTED
	void Redo();
	Vector GetCarSpawnLocation();
	void SetCarSpawnLocation(Vector v);
	Rotator GetCarSpawnRotation();
	void SetCarSpawnRotation(Rotator v);
	CarWrapper GetGameCar();
	bool IsBallMovingTowardsGoal(int32_t goalNo, BallWrapper bw);
	bool IsInGoal(Vector vec);
	void DisableGoalReset();
	void EnableGoalReset();
	//void SpawnCar(int32_t body = 0);
	//Speed from 0 to 2000 pls
	Vector GenerateShot(Vector startPos, Vector destination, float speed);
	Vector GenerateGoalAimLocation(int32_t goalNumber, Vector currentBallLocation);
	Vector GetGoalExtent(int32_t goalNumber = 0);
	Vector GetGoalLocation(int32_t goalNumber = 0);	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	Vector GetTotalFieldExtent();
	void SetTotalFieldExtent(Vector newTotalFieldExtent);
	int32_t GetTeamNum();
	void SetTeamNum(int32_t newTeamNum);
	int32_t GetBallGoalNum();
	void SetBallGoalNum(int32_t newBallGoalNum);
	unsigned long GetbOnlyScoreInBallGoalNum();
	void SetbOnlyScoreInBallGoalNum(unsigned long newbOnlyScoreInBallGoalNum);
	unsigned long GetbRedoRound();
	void SetbRedoRound(unsigned long newbRedoRound);
	unsigned long GetbAllowSuperBoost();
	void SetbAllowSuperBoost(unsigned long newbAllowSuperBoost);
	unsigned long GetbDisplayedRedoPenaltyMessage();
	void SetbDisplayedRedoPenaltyMessage(unsigned long newbDisplayedRedoPenaltyMessage);
	unsigned long GetbShowBoostMeter();
	void SetbShowBoostMeter(unsigned long newbShowBoostMeter);
	uint8_t GetDifficulty();
	void SetDifficulty(uint8_t newDifficulty);
	uint8_t GetDebugRotationType();
	void SetDebugRotationType(uint8_t newDebugRotationType);
	float GetGoalDepth();
	void SetGoalDepth(float newGoalDepth);
	int32_t GetGameEventRounds();
	void SetGameEventRounds(int32_t newGameEventRounds);
	float GetEventStartTime();
	void SetEventStartTime(float newEventStartTime);
	Vector GetBallInitialVelocity();
	void SetBallInitialVelocity(Vector newBallInitialVelocity);
	int32_t GetSpawnIndexTypeOverride();
	void SetSpawnIndexTypeOverride(int32_t newSpawnIndexTypeOverride);
	int32_t GetWaveIndex();
	void SetWaveIndex(int32_t newWaveIndex);
	int32_t GetWaveSpawnCount();
	void SetWaveSpawnCount(int32_t newWaveSpawnCount);
	int32_t GetRandomSpawnIndex();
	void SetRandomSpawnIndex(int32_t newRandomSpawnIndex);
	UnrealStringWrapper GetStartMessageArchetype();
	Vector GetBallSpawnLocation();
	void SetBallSpawnLocation(Vector newBallSpawnLocation);
	int32_t GetPointsScoredThisRound();
	void SetPointsScoredThisRound(int32_t newPointsScoredThisRound);
	int32_t GetBallSpawnCount();
	void SetBallSpawnCount(int32_t newBallSpawnCount);
	float GetBallBounceScale();
	void SetBallBounceScale(float newBallBounceScale);
	int32_t GetCurrentDebugStepX();
	void SetCurrentDebugStepX(int32_t newCurrentDebugStepX);
	int32_t GetCurrentDebugStepY();
	void SetCurrentDebugStepY(int32_t newCurrentDebugStepY);
	int32_t GetCurrentDebugStepZ();
	void SetCurrentDebugStepZ(int32_t newCurrentDebugStepZ);
	int32_t GetRedoCount();
	void SetRedoCount(int32_t newRedoCount);
	int32_t GetRedoTotal();
	void SetRedoTotal(int32_t newRedoTotal);

	//AUTO-GENERATED FUNCTION PROXIES
	void InitIntro();
	void OnLoadingMovieClosed();
	void StartTimers();
	void UpdateMVP();
	bool AllowDynamicCrowd();
	void SetTutorialTip(std::string NewTip);
	void SetShowBoostMeter(unsigned long bShow);
	float GetStepLoc(int32_t Steps, float TotalDist, unsigned long bIncrement, int32_t* Out_CurrentStep);
	Vector GetDebugLocationInExtent(Vector& Extent);
	void InitDebugSetup(CarWrapper Car);
	void SkipTutorial();
	void UpdateBotCount();
	void InitMutators();
	bool IsPrimaryPlayer(CarWrapper Car);
	bool CanAwardPoints();
	void ShowResetRoundMessage();
	void Destroyed();
	bool EndTutorial();
	void CommitRedoRound();
	void RedoRound2();
	bool CanRedoRound();
	void StartNewRound();
	void SaveLocalPlayerStats();
	TeamWrapper GetWinningTeam();
	void CleanupRoundActors();
	bool CanQueSaveReplay();
	void ResetBalls();
	int32_t GetScore();
	void StartRound();
	int32_t GetGameEventRounds2();
	int32_t GetTotalRounds();
	void ResetRoundTime();
	void OnPlayerRestarted(CarWrapper PlayerCar);
	uint8_t GetTrainingType();
	void EndGame();
	Vector GetRandomLocationInExtent(Vector& Extent);
	bool Chance(int32_t Chances);
	int32_t GetOppositeTeamNum();
	Vector GetDirectionToGoal(int32_t GoalNum);
	bool IsGameEventComplete();
	Vector ClampPointToExtent(Vector& ExtentCenter, Vector& Point, Vector& Extent);
	Vector PredictInitialVelocity(Vector& StartLoc, Vector& EndLoc, float Z);
	BallWrapper GetGameBall();
	CarWrapper GetGamePawn();
	void ResetGameEvent();
	void CheckForReset();
	float GetGoalViewWidth(GoalWrapper Goal, Vector& ViewerLoc);
	bool IsBallMovingTowardsGoal2(GoalWrapper Goal, BallWrapper Ball, float MinVelocityForDestroy, float InGoalDepth);
	void SetGoalDepth2();
	int32_t GetShuffledSpawnIndex();
	void DestroyCannon();
	void SetCannonOrientation(Vector& NewLocation, Rotator& NewRotation);
	BallWrapper SpawnBall(Vector& SpawnLoc, unsigned long bWake, unsigned long bSpawnCannon, std::string BallArch);
	void InitBallEffects();
	void InitBallVelocity();
	Vector GetRandomGoalAimLocation(int32_t InTeamNum, Vector& BallLoc);
	Vector GetGoalExtent2(GoalWrapper Goal);
	void SetBallVelocity(Vector& InitialVelocity, BallWrapper Ball);
	void InitGameSetup(CarWrapper Car);
	bool ShouldAllowSuperBoost();
	void OnVehicleSetup(CarWrapper Car);
	void HandleVehicleSetup(CarWrapper Car);
	void InitCrowdManager();
	void HandleScoreUpdated(TeamWrapper Team);
	void SetDifficulty2(int32_t InDifficulty);
	void UpdateStats();
	void AddLocalPlayer(PlayerControllerWrapper Player);
	void HandlePlayerResetTraining(GameEventWrapper GameEvent);
	void OnInit();
	void EventTutorialTipChanged(TutorialWrapper GameEvent, std::string NewTip);
private:
	PIMPL
};