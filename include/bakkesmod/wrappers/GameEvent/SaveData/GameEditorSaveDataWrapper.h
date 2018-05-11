#pragma once
template<class T> class ArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameEvent/SaveData/SaveDataWrapper.h"
class TrainingEditorSaveDataWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameEditorSaveDataWrapper : public SaveDataWrapper {
public:
	CONSTRUCTORS(GameEditorSaveDataWrapper)

	//AUTO-GENERATED FROM FIELDS
	TrainingEditorSaveDataWrapper GetTrainingData();
	void SetTrainingData(TrainingEditorSaveDataWrapper newTrainingData);
	int GetPlayerTeamNumber();
	void SetPlayerTeamNumber(int newPlayerTeamNumber);
	unsigned long GetbUnowned();
	void SetbUnowned(unsigned long newbUnowned);
	int GetShotsCompleted();
	void SetShotsCompleted(int newShotsCompleted);

	//AUTO-GENERATED FUNCTION PROXIES
	unsigned char GetTrainingSaveType(unsigned long bOwned, unsigned long bFavorited);
	void Init();
private:
	PIMPL
};