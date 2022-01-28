#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/GameEditorWrapper.h"
class PlayerControllerWrapper;
class UnrealStringWrapper;
class ActorWrapper;
class GameEditorSaveDataWrapper;
class BallWrapper;

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
	int32_t GetPointsScoredThisRound();
	void SetPointsScoredThisRound(int32_t newPointsScoredThisRound);
	int32_t GetShotAttempt();
	void SetShotAttempt(int32_t newShotAttempt);
	int32_t GetGoalieScore();
	void SetGoalieScore(int32_t newGoalieScore);
	uint8_t GetPlayTestType();
	void SetPlayTestType(uint8_t newPlayTestType);
	ArrayWrapper<ActorWrapper> GetGoalMeshBlockers();
	ActorWrapper GetGoalMeshBlockerArchetype();
	void SetGoalMeshBlockerArchetype(ActorWrapper newGoalMeshBlockerArchetype);
	GameEditorSaveDataWrapper GetTrainingData();
	void SetTrainingData(GameEditorSaveDataWrapper newTrainingData);
	float GetSaveDelayTime();
	void SetSaveDelayTime(float newSaveDelayTime);
	float GetSaveCooldown();
	void SetSaveCooldown(float newSaveCooldown);
	UnrealStringWrapper GetTrainingFileName();

	//AUTO-GENERATED FUNCTION PROXIES
	void OnLoadingMovieClosed();
	void TagHistoryChanges();
	void MarkAsDirty();
	void ForceTagHistoryChanges();
	void SetTracedCrosshairActor(PlayerControllerWrapper PC, ActorWrapper NewActor);
	bool DestroyBall(BallWrapper Ball);
	bool AllowDynamicCrowd();
	void BroadcastGoMessage();
	int32_t GetTotalRounds();
	uint8_t GetDifficulty();
	uint8_t GetTrainingType();
	void Save2();
	void OnTrainingModeLoaded();
	void DuplicateRound(int32_t Index);
	void ReorderRound(int32_t FromIndex, int32_t ToIndex);
	void SetRoundTimeLimit(float NewRoundTime);
	bool HandleNextGame();
	void ResetBalls();
	void Load2(std::string SaveName, PlayerControllerWrapper PC);
	void DestroyGoalMeshBlockers();
	void UpdateGoalMeshBlocker();
	int32_t GetScore();
	void RemovePointsFromScore(int32_t PointsToRemove, int32_t TeamIndex);
	bool ShowScorerGoalMessage();
	void ShowResetRoundMessage();
	bool ShowPenaltyMessage();
	int32_t GetPlayerTeamNumber();
	int32_t GetBallGoalScoreNumber();
	void RemoveAllPointsFromScore(int32_t TeamIndex);
	bool IncrementRound(unsigned long bLoop);
	Vector AdjustToFloorLocation(Vector& TraceStart, Vector& CollsionExtent);
	ActorWrapper SpawnArchetypeAtAndAdjustToFloor(ActorWrapper Archetype, Vector& SpawnLocation, Rotator& SpawnRotation);
	void SpawnBallAndStartPointAt(Vector& BallSpawnLocation, Rotator& BallSpawnRotation, Vector& StartPointSpawnLocation, Rotator& StartPointSpawnRotation);
	void SetupDefaultRound();
	void SwitchToRoundNumber(int32_t RoundNumber, unsigned long BackupCurrentRound);
	void DeleteRound(int32_t RoundToDelete);
	void RestartPlayTest();
	void EndPlayTest();
	void StartPlayTest(uint8_t InPlayTestType);
	bool CanPlayTestRoundNumber(int32_t RoundNumber);
	void SetUnsavedChanges(unsigned long bInUnsavedChanges);
	void UpdateActiveRoundData();
	void StartNewRound();
	bool IsValidRoundIndex(int32_t ArrayIndex);
	void AddLocalPlayer(PlayerControllerWrapper Player);
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