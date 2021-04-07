#pragma once
#include "../Engine/ObjectWrapper.h"
#include "OnlineProductWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT TradeWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(TradeWrapper)

	ArrayWrapper<OnlineProductWrapper> GetReceivingProducts();
	ArrayWrapper<OnlineProductWrapper> GetSendingProducts();
	bool IsNull();
	explicit operator bool();

private:
	PIMPL
};