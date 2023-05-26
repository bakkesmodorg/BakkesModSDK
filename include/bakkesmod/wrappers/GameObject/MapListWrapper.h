#pragma once
#include "MapDataWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT MapListWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(MapListWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD ArrayWrapper<MapDataWrapper> GetSortedMaps() const;

private:
	PIMPL
	
};

