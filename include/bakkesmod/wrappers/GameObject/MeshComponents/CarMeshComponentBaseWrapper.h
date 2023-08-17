#pragma once
#include "SkeletalMeshComponentWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT CarMeshComponentBaseWrapper : public SkeletalMeshComponentWrapper
{
public:
	CONSTRUCTORS(CarMeshComponentBaseWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	_NODISCARD CarWrapper GetCar() const;

	//END SELF IMPLEMENTED

private:
	PIMPL
	
};
