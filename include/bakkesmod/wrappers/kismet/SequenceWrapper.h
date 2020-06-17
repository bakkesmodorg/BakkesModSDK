#pragma once
#include "SequenceOpWrapper.h"
#include "../arraywrapper.h"

class SequenceVariableWrapper;

class BAKKESMOD_PLUGIN_IMPORT SequenceWrapper : public SequenceOpWrapper {
public:
	CONSTRUCTORS(SequenceWrapper)

	ArrayWrapper<SequenceObjectWrapper>	GetSequenceObjects();
	ArrayWrapper<SequenceWrapper>		GetNestedSequences();

	// self implemented
	// BFS search trough nested sequences and their contained SequenceObjects
	//  don't think they change, so user could probably cache this..
	std::map<std::string, SequenceVariableWrapper> GetAllSequenceVariables(bool reqursive);

private:
	PIMPL
};