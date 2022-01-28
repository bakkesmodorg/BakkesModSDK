#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT TrainingEditorSaveDataWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(TrainingEditorSaveDataWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetCode();
	UnrealStringWrapper GetTM_Name();
	uint8_t GetType();
	void SetType(uint8_t newType);
	uint8_t GetDifficulty();
	void SetDifficulty(uint8_t newDifficulty);
	UnrealStringWrapper GetCreatorName();
	UnrealStringWrapper GetDescription();
	int32_t GetNumRounds();
	void SetNumRounds(int32_t newNumRounds);
	uint64_t GetCreatedAt();
	void SetCreatedAt(uint64_t newCreatedAt);
	uint64_t GetUpdatedAt();
	void SetUpdatedAt(uint64_t newUpdatedAt);

	[[deprecated("Use GetCreatorPlayerUniqueID instead")]]
	SteamID GetCreatorPlayerID(); //DEPRECATED
	
	void SetCreatorPlayerID(SteamID newCreatorPlayerID);

	//AUTO-GENERATED FUNCTION PROXIES
	void Init();

	//SELF-IMPLEMENTED
	UniqueIDWrapper GetCreatorPlayerUniqueID();
private:
	PIMPL
};