#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/ServerWrapper.h"
class PlayerControllerWrapper;
class CarWrapper;
class ActorWrapper;
class FXActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameEditorWrapper : public ServerWrapper {
public:
	CONSTRUCTORS(GameEditorWrapper)

	//AUTO-GENERATED FROM FIELDS
	int32_t GetActiveRoundNumber();
	void SetActiveRoundNumber(int32_t newActiveRoundNumber);
	int32_t GetMaxRounds();
	void SetMaxRounds(int32_t newMaxRounds);
	int32_t GetHistoryPosition();
	void SetHistoryPosition(int32_t newHistoryPosition);
	int32_t GetMaxUndoHistory();
	void SetMaxUndoHistory(int32_t newMaxUndoHistory);
	FXActorWrapper GetFXActorArchetype();
	void SetFXActorArchetype(FXActorWrapper newFXActorArchetype);
	FXActorWrapper GetFXActor();
	void SetFXActor(FXActorWrapper newFXActor);

	//AUTO-GENERATED FUNCTION PROXIES
	void RotateActor(PlayerControllerWrapper PC, unsigned long bSnapOrientation);
	void PrevRound();
	void NextRound();
	void DecreaseTime();
	void IncreaseTime();
	void StopEditing(PlayerControllerWrapper PC);
	void StartEditing();
	void CycleActor(PlayerControllerWrapper PC);
	void ReleaseGrabbedActor(PlayerControllerWrapper PC);
	void ReleaseRotateActor(PlayerControllerWrapper PC);
	void ToggleRotateActor(PlayerControllerWrapper PC);
	void ToggleGrabActor(PlayerControllerWrapper PC);
	void ToggleReleaseActor(PlayerControllerWrapper PC);
	void ReleaseActor2(PlayerControllerWrapper PC);
	void GrabActor2(PlayerControllerWrapper PC);
	bool CanQueSaveReplay();
	bool ShouldUpdateCrosshair();
	int32_t GetPlayerTeamNumber();
	bool CanAddHistory();
	void ToggleEditorRound();
	void CommitRedoRound();
	void ResetRound();
	void Save2();
	void Redo2(PlayerControllerWrapper PC);
	void Undo2(PlayerControllerWrapper PC);
	uint8_t GetOtherHistoryType(uint8_t HistoryType);
	void ClampUndoHistory();
	void ClearRedoHistory();
	void ClearAllHistory();
	bool DestroyActor(ActorWrapper A, uint8_t HistoryType);
	bool IsInEditorMode();
	void RemoveAllPointsFromScore(int32_t TeamIndex);
	void RemovePointsFromScore(int32_t PointsToRemove, int32_t TeamIndex);
	void DeleteAllExistingActorsBasedOffSpawnList();
	bool RoundContainsASwitch();
	void EnableTriggers(unsigned long bEnable);
	void HideCarSpawnPoints(unsigned long bHide);
	void ResetSpawnLocations();
	void OnSpawnedArchetype(ActorWrapper SpawnedActor, uint8_t HistoryType);
	void SpawnArchetype(PlayerControllerWrapper Controller, int32_t ArchetypeIndex);
	void IncrementSelectedSpawnArchetypeIndex(int32_t Direction, int32_t* Index);

	[[deprecated("Removed from Rocket League, defaults to false")]]
	bool CanChangeTeam();
	void ResetBallsToDefaultPosition();
	void FireBalls();
	void Interact();
	bool ShouldResetBalls();
	void OnVehicleSetup(CarWrapper Car);
	void HandleVehicleSetup(CarWrapper Car);
	void OnPlayerRestarted(CarWrapper PlayerCar);
	bool ChooseTeam(int32_t TeamIndex, PlayerControllerWrapper Player);
	void InitFX();
	void eventPostBeginPlay();
private:
	PIMPL
};