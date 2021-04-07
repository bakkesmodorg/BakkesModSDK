#pragma once
#include "SequenceOpWrapper.h"
#include "../arraywrapper.h"
#include <map>

class SequenceVariableWrapper;

class BAKKESMOD_PLUGIN_IMPORT SequenceWrapper : public SequenceOpWrapper {
public:
	CONSTRUCTORS(SequenceWrapper)

	ArrayWrapper<SequenceObjectWrapper>	GetSequenceObjects();
	ArrayWrapper<SequenceWrapper>		GetNestedSequences();

	/// <summary>
	/// Searches this sequence recursively for RemoteEvents with the right name and activates them
	/// </summary>
	/// <param name="remote_event_name">The name of the event to activate</param>
	/// <returns>The amount of nodes activated</returns>
	int ActivateRemoteEvents(const std::string& remote_event_name) const;

	// self implemented
	// BFS search trough nested sequences and their contained SequenceObjects
	//  don't think they change, so user could probably cache this..
	std::map<std::string, SequenceVariableWrapper> GetAllSequenceVariables(bool reqursive);

private:
	PIMPL
};