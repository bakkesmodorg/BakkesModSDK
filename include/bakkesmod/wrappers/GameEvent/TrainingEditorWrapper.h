#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/GameEditorWrapper.h"
class GameEditorSaveDataWrapper;
class ActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT TrainingEditorWrapper : public GameEditorWrapper {
public:
	CONSTRUCTORS(TrainingEditorWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetMinRoundTime();
	void SetMinRoundTime(float newMinRoundTime);
	float GetMaxRoundTime();
	void SetMaxRoundTime(float newMaxRoundTime);
	unsigned long GetbNoEditor();
	void SetbNoEditor(unsigned long newbNoEditor);
	unsigned long GetbDisplayedRedoPenaltyMessage();
	void SetbDisplayedRedoPenaltyMessage(unsigned long newbDisplayedRedoPenaltyMessage);
	unsigned long GetbUnsavedChanges();
	void SetbUnsavedChanges(unsigned long newbUnsavedChanges);
	int GetPointsScoredThisRound();
	void SetPointsScoredThisRound(int newPointsScoredThisRound);
	int GetShotAttempt();
	void SetShotAttempt(int newShotAttempt);
	int GetGoalieScore();
	void SetGoalieScore(int newGoalieScore);
	unsigned char GetPlayTestType();
	void SetPlayTestType(unsigned char newPlayTestType);
	ArrayWrapper<ActorWrapper> GetGoalMeshBlockers();
	ActorWrapper GetGoalMeshBlockerArchetype();
	void SetGoalMeshBlockerArchetype(ActorWrapper newGoalMeshBlockerArchetype);
	GameEditorSaveDataWrapper GetTrainingData();
	void SetTrainingData(GameEditorSaveDataWrapper newTrainingData);
	float GetSaveDelayTime();
	void SetSaveDelayTime(float newSaveDelayTime);
	float GetSaveCooldown();
	void SetSaveCooldown(float newSaveCooldown);

	//AUTO-GENERATED FUNCTION PROXIES
	bool AllowDynamicCrowd();
	void BroadcastGoMessage();
	int GetTotalRounds();
	unsigned char GetDifficulty();
	unsigned char GetTrainingType();
	void Save2();
	void OnTrainingModeLoaded();
	void DuplicateRound(int Index);
	void ReorderRound(int FromIndex, int ToIndex);
	void SetRoundTimeLimit(float NewRoundTime);
	bool HandleNextGame();
	void ResetBalls();
	void DestroyGoalMeshBlockers();
	void UpdateGoalMeshBlocker();
	int GetScore();
	bool CanAwardAchievements();
	void RemovePointsFromScore(int PointsToRemove, int TeamIndex);
	bool ShowScorerGoalMessage();
	void ShowResetRoundMessage();
	bool ShowPenaltyMessage();
	int GetPlayerTeamNumber();
	int GetBallGoalScoreNumber();
	void RemoveAllPointsFromScore(int TeamIndex);
	bool IncrementRound(unsigned long bLoop);
	Vector AdjustToFloorLocation(Vector& TraceStart, Vector& CollsionExtent);
	ActorWrapper SpawnArchetypeAtAndAdjustToFloor(ActorWrapper Archetype, Vector& SpawnLocation, Rotator& SpawnRotation);
	void SpawnBallAndStartPointAt(Vector& BallSpawnLocation, Rotator& BallSpawnRotation, Vector& StartPointSpawnLocation, Rotator& StartPointSpawnRotation);
	void SetupDefaultRound();
	void SwitchToRoundNumber(int RoundNumber, unsigned long BackupCurrentRound);
	void DeleteRound(int RoundToDelete);
	void RestartPlayTest();
	void EndPlayTest();
	void StartPlayTest(unsigned char InPlayTestType);
	bool CanPlayTestRoundNumber(int RoundNumber);
	void SetUnsavedChanges(unsigned long bInUnsavedChanges);
	void UpdateActiveRoundData();
	void StartNewRound();
	bool IsValidRoundIndex(int ArrayIndex);
	void OnInit();
	void eventDestroyed();
	void eventPostBeginPlay();
	void EventSaveResult(unsigned long bSuccess);
	void EventUnsavedChanges(unsigned long bOutUnsavedChanges);
	void EventPlaytestStarted(TrainingEditorWrapper GamEvent);
	void EventRoundChanged(TrainingEditorWrapper GamEvent);
	void EventRoundTimeChanged(TrainingEditorWrapper GameEvent);
private:
	PIMPL
};