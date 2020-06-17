#pragma once
#include "SequenceObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT SequenceVariableWrapper : public SequenceObjectWrapper {
public:
	CONSTRUCTORS(SequenceVariableWrapper)

	std::string GetVarName();

    // Custom implementation
    bool                IsInt();
    bool                IsFloat();
    bool                IsString();
    bool                IsVector();
    bool                IsBool();

    float               GetFloat();
    int                 GetInt();
    std::string         GetString();
    Vector              GetVector();
    bool                GetBool();

private:
	PIMPL
};