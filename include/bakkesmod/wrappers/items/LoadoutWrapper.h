#pragma once
#include "../Engine/ObjectWrapper.h"
#include "../arraywrapper.h"
class ProductWrapper;
class OnlineProductWrapper;

class BAKKESMOD_PLUGIN_IMPORT LoadoutWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(LoadoutWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	
	ArrayWrapper<int> GetLoadout();
	ArrayWrapper<unsigned long long> GetOnlineLoadout();
	unsigned char GetPrimaryPaintColorId();
	unsigned char GetAccentPaintColorId();
	int GetPrimaryFinishId();
	int GetAccentFinishId();
	
private:
	PIMPL
};

