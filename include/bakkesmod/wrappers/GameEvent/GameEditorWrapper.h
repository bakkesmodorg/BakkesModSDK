#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameEvent/ServerWrapper.h"
class CarWrapper;
class ActorWrapper;

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

	//AUTO-GENERATED FUNCTION PROXIES
	void PrevRound();
	void NextRound();
	void DecreaseTime();
	void IncreaseTime();
	void StartEditing();
	bool CanQueSaveReplay();
	bool ShouldUpdateCrosshair();
	int GetPlayerTeamNumber();
	bool CanAddHistory();
	void ToggleEditorRound();
	void CommitRedoRound();
	void ResetRound();
	void Save2();
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
	void IncrementSelectedSpawnArchetypeIndex(int Direction, int* Index);
	bool CanChangeTeam();
	void ResetBallsToDefaultPosition();
	void FireBalls();
	void Interact();
	bool ShouldResetBalls();
	void OnVehicleSetup(CarWrapper Car);
	void HandleVehicleSetup(CarWrapper Car);
	void OnPlayerRestarted(CarWrapper PlayerCar);
	void InitFX();
	void eventPostBeginPlay();
private:
	PIMPL
};