#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT SaveDataWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(SaveDataWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetDirectoryPath();
	UnrealStringWrapper GetSaveType();
	UnrealStringWrapper GetSaveExt();
	unsigned long GetbExactFileMatch();
	void SetbExactFileMatch(unsigned long newbExactFileMatch);

	//AUTO-GENERATED FUNCTION PROXIES
	void Init();
private:
	PIMPL
};