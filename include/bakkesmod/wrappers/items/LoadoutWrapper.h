#pragma once
#include "../Engine/ObjectWrapper.h"
#include "../arraywrapper.h"
#include <vector>

class BAKKESMOD_PLUGIN_IMPORT LoadoutWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(LoadoutWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	
	ArrayWrapper<int> GetLoadout();
	[[deprecated("Missing half the data")]]
	ArrayWrapper<unsigned long long> GetOnlineLoadout();
	_NODISCARD std::vector<ProductInstanceID> GetOnlineLoadoutV2() const;
	unsigned char GetPrimaryPaintColorId();
	unsigned char GetAccentPaintColorId();
	int GetPrimaryFinishId();
	int GetAccentFinishId();
	
private:
	PIMPL
};

