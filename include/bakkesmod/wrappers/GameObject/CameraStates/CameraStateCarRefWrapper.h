#pragma once
#include "CameraStateWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT CameraStateCarRefWrapper : public CameraStateWrapper
{
public:
	CONSTRUCTORS(CameraStateCarRefWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

private:
	PIMPL
	
};
