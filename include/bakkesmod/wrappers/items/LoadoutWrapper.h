#pragma once
#include "../Engine/ObjectWrapper.h"
#include "../arraywrapper.h"
class ProductWrapper;
class OnlineProductWrapper;

class BAKKESMOD_PLUGIN_IMPORT LoadoutWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(LoadoutWrapper)

	ArrayWrapper<int> GetLoadout();
	ArrayWrapper<unsigned long long> GetOnlineLoadout();
	
private:
	PIMPL
};

