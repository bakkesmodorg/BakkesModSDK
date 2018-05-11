#pragma once
template<class T> class ArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT SaveDataWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(SaveDataWrapper)

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbExactFileMatch();
	void SetbExactFileMatch(unsigned long newbExactFileMatch);

	//AUTO-GENERATED FUNCTION PROXIES
	void Init();
private:
	PIMPL
};