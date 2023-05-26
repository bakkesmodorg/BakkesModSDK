#pragma once
#include "CameraStateXWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT CameraStateWrapper : public CameraStateXWrapper
{
public:
	CONSTRUCTORS(CameraStateWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

private:
	PIMPL
	
};
