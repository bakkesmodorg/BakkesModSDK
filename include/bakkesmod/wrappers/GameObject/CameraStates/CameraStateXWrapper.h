#pragma once

#include "bakkesmod/wrappers/Engine/ObjectWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT CameraStateXWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(CameraStateXWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	_NODISCARD std::string GetStateType() const;
	//END SELF IMPLEMENTED

private:
	PIMPL
	
};
