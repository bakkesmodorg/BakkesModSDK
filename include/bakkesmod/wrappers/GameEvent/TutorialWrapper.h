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
	bool IsBallMovingTowardsGoal(int goalNo, BallWrapper bw);
	bool IsInGoal(Vector vec);
	void DisableGoalReset();
	void EnableGoalReset();
	//void SpawnCar(int body = 0);
	//Speed from 0 to 2000 pls
	Vector GenerateShot(Vector startPos, Vector destination, float speed);
	Vector GenerateGoalAimLocation(int goalNumber, Vector currentBallLocation);
	Vector GetGoalExtent(int goalNumber = 0);
	Vector GetGoalLocation(int goalNumber = 0);	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	Vector GetTotalFieldExtent();
	void SetTotalFieldExtent(Vector newTotalFieldExtent);
	int GetTeamNum();
	void SetTeamNum(int newTeamNum);
	int GetBallGoalNum();
	void SetBallGoalNum(int newBallGoalNum);
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
	unsigned char GetDifficulty();
	void SetDifficulty(unsigned char newDifficulty);
	unsigned char GetDebugRotationType();
	void SetDebugRotationType(unsigned char newDebugRotationType);
	float GetGoalDepth();
	void SetGoalDepth(float newGoalDepth);
	int GetGameEventRounds();
	void SetGameEventRounds(int newGameEventRounds);
	float GetEventStartTime();
	void SetEventStartTime(float newEventStartTime);
	Vector GetBallInitialVelocity();
	void SetBallInitialVelocity(Vector newBallInitialVelocity);
	int GetSpawnIndexTypeOverride();
	void SetSpawnIndexTypeOverride(int newSpawnIndexTypeOverride);
	int GetWaveIndex();
	void SetWaveIndex(int newWaveIndex);
	int GetWaveSpawnCount();
	void SetWaveSpawnCount(int newWaveSpawnCount);
	int GetRandomSpawnIndex();
	void SetRandomSpawnIndex(int newRandomSpawnIndex);
	UnrealStringWrapper GetStartMessageArchetype();
	Vector GetBallSpawnLocation();
	void SetBallSpawnLocation(Vector newBallSpawnLocation);
	int GetPointsScoredThisRound();
	void SetPointsScoredThisRound(int newPointsScoredThisRound);
	int GetBallSpawnCount();
	void SetBallSpawnCount(int newBallSpawnCount);
	float GetBallBounceScale();
	void SetBallBounceScale(float newBallBounceScale);
	int GetCurrentDebugStepX();
	void SetCurrentDebugStepX(int newCurrentDebugStepX);
	int GetCurrentDebugStepY();
	void SetCurrentDebugStepY(int newCurrentDebugStepY);
	int GetCurrentDebugStepZ();
	void SetCurrentDebugStepZ(int newCurrentDebugStepZ);
	int GetRedoCount();
	void SetRedoCount(int newRedoCount);
	int GetRedoTotal();
	void SetRedoTotal(int newRedoTotal);

	//AUTO-GENERATED FUNCTION PROXIES
	void InitIntro();
	void OnLoadingMovieClosed();
	void StartTimers();
	void UpdateMVP();
	bool AllowDynamicCrowd();
	void SetTutorialTip(std::string NewTip);
	void SetShowBoostMeter(unsigned long bShow);
	float GetStepLoc(int Steps, float TotalDist, unsigned long bIncrement, int* Out_CurrentStep);
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
	int GetScore();
	void StartRound();
	int GetGameEventRounds2();
	int GetTotalRounds();
	void ResetRoundTime();
	void OnPlayerRestarted(CarWrapper PlayerCar);
	unsigned char GetTrainingType();
	void EndGame();
	Vector GetRandomLocationInExtent(Vector& Extent);
	bool Chance(int Chances);
	int GetOppositeTeamNum();
	Vector GetDirectionToGoal(int GoalNum);
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
	int GetShuffledSpawnIndex();
	void DestroyCannon();
	void SetCannonOrientation(Vector& NewLocation, Rotator& NewRotation);
	BallWrapper SpawnBall(Vector& SpawnLoc, unsigned long bWake, unsigned long bSpawnCannon, std::string BallArch);
	void InitBallEffects();
	void InitBallVelocity();
	Vector GetRandomGoalAimLocation(int InTeamNum, Vector& BallLoc);
	Vector GetGoalExtent2(GoalWrapper Goal);
	void SetBallVelocity(Vector& InitialVelocity, BallWrapper Ball);
	void InitGameSetup(CarWrapper Car);
	bool ShouldAllowSuperBoost();
	void OnVehicleSetup(CarWrapper Car);
	void HandleVehicleSetup(CarWrapper Car);
	void InitCrowdManager();
	void HandleScoreUpdated(TeamWrapper Team);
	void SetDifficulty2(int InDifficulty);
	void UpdateStats();
	void AddLocalPlayer(PlayerControllerWrapper Player);
	void HandlePlayerResetTraining(GameEventWrapper GameEvent);
	void OnInit();
	void EventTutorialTipChanged(TutorialWrapper GameEvent, std::string NewTip);
private:
	PIMPL
};