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
	int GetActiveRoundNumber();
	void SetActiveRoundNumber(int newActiveRoundNumber);
	int GetMaxRounds();
	void SetMaxRounds(int newMaxRounds);
	int GetHistoryPosition();
	void SetHistoryPosition(int newHistoryPosition);
	int GetMaxUndoHistory();
	void SetMaxUndoHistory(int newMaxUndoHistory);
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
	int GetPlayerTeamNumber();
	bool CanAddHistory();
	void ToggleEditorRound();
	void CommitRedoRound();
	void ResetRound();
	void Save2();
	void Redo2(PlayerControllerWrapper PC);
	void Undo2(PlayerControllerWrapper PC);
	unsigned char GetOtherHistoryType(unsigned char HistoryType);
	void ClampUndoHistory();
	void ClearRedoHistory();
	void ClearAllHistory();
	bool DestroyActor(ActorWrapper A, unsigned char HistoryType);
	bool IsInEditorMode();
	void RemoveAllPointsFromScore(int TeamIndex);
	void RemovePointsFromScore(int PointsToRemove, int TeamIndex);
	void DeleteAllExistingActorsBasedOffSpawnList();
	bool RoundContainsASwitch();
	void EnableTriggers(unsigned long bEnable);
	void HideCarSpawnPoints(unsigned long bHide);
	void ResetSpawnLocations();
	void OnSpawnedArchetype(ActorWrapper SpawnedActor, unsigned char HistoryType);
	void SpawnArchetype(PlayerControllerWrapper Controller, int ArchetypeIndex);
	void IncrementSelectedSpawnArchetypeIndex(int Direction, int* Index);

	[[deprecated("Removed from Rocket League, defaults to false")]]
	bool CanChangeTeam();
	void ResetBallsToDefaultPosition();
	void FireBalls();
	void Interact();
	bool ShouldResetBalls();
	void OnVehicleSetup(CarWrapper Car);
	void HandleVehicleSetup(CarWrapper Car);
	void OnPlayerRestarted(CarWrapper PlayerCar);
	bool ChooseTeam(int TeamIndex, PlayerControllerWrapper Player);
	void InitFX();
	void eventPostBeginPlay();
private:
	PIMPL
};