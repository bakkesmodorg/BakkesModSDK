#pragma once
#include "SequenceObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT SequenceVariableWrapper : public SequenceObjectWrapper {
public:
	CONSTRUCTORS(SequenceVariableWrapper)

	std::string GetVarName();

	// Custom implementation
	bool IsInt();
	bool IsFloat();
	bool IsString();
	bool IsVector();
	bool IsBool();
	bool IsObjectList();
	bool IsActor();

	float GetFloat();
	int GetInt();
	std::string GetString();
	Vector GetVector();
	bool GetBool();
	ArrayWrapper<SequenceVariableWrapper> GetObjectList();

	
	void SetFloat(float value);
	void SetInt(int value);
	void SetString(const std::string& value);
	void SetVector(Vector value);
	void SetBool(bool value);
	ActorWrapper GetActor();

private:
	PIMPL
};