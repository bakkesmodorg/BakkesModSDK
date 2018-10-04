#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT TrainingEditorSaveDataWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(TrainingEditorSaveDataWrapper)

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetCode();
	UnrealStringWrapper GetTM_Name();
	unsigned char GetType();
	void SetType(unsigned char newType);
	unsigned char GetDifficulty();
	void SetDifficulty(unsigned char newDifficulty);
	UnrealStringWrapper GetCreatorName();
	UnrealStringWrapper GetDescription();
	int GetNumRounds();
	void SetNumRounds(int newNumRounds);
	SteamID GetCreatorPlayerID();
	void SetCreatorPlayerID(SteamID newCreatorPlayerID);

	//AUTO-GENERATED FUNCTION PROXIES
	void Init();
private:
	PIMPL
};