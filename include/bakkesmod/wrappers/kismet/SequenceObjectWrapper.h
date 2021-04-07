#pragma once
#include ".././Engine/ObjectWrapper.h"

class SequenceWrapper;
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT SequenceObjectWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(SequenceObjectWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	SequenceWrapper     GetParentSequence();
	UnrealStringWrapper GetObjName();
	UnrealStringWrapper GetObjCategory();
	UnrealStringWrapper GetObjComment();

private:
	PIMPL
};