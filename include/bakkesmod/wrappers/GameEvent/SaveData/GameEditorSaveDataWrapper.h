#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameEvent/SaveData/SaveDataWrapper.h"
class TrainingEditorSaveDataWrapper;
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameEditorSaveDataWrapper : public SaveDataWrapper {
public:
	CONSTRUCTORS(GameEditorSaveDataWrapper)

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetLoadedSaveName();
	TrainingEditorSaveDataWrapper GetTrainingData();
	void SetTrainingData(TrainingEditorSaveDataWrapper newTrainingData);
	int32_t GetPlayerTeamNumber();
	void SetPlayerTeamNumber(int32_t newPlayerTeamNumber);
	unsigned long GetbUnowned();
	void SetbUnowned(unsigned long newbUnowned);
	int32_t GetShotsCompleted();
	void SetShotsCompleted(int32_t newShotsCompleted);
	UnrealStringWrapper GetFavoritesFolderPath();
	UnrealStringWrapper GetMyTrainingFolderPath();
	UnrealStringWrapper GetDownloadedFolderPath();

	//AUTO-GENERATED FUNCTION PROXIES
	uint8_t GetTrainingSaveType(unsigned long bOwned, unsigned long bFavorited);
	void Init();
private:
	PIMPL
};