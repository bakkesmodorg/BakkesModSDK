#pragma once
template<class T> class ArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT TrainingEditorSaveDataWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(TrainingEditorSaveDataWrapper)

	//AUTO-GENERATED FROM FIELDS
	unsigned char GetType();
	void SetType(unsigned char newType);
	unsigned char GetDifficulty();
	void SetDifficulty(unsigned char newDifficulty);
	int GetNumRounds();
	void SetNumRounds(int newNumRounds);

	//AUTO-GENERATED FUNCTION PROXIES
	void Init();
private:
	PIMPL
};