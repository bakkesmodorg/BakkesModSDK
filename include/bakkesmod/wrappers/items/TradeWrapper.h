#pragma once
#include "../Engine/ObjectWrapper.h"
#include "OnlineProductWrapper.h"



class BAKKESMOD_PLUGIN_IMPORT TradeWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(TradeWrapper)

	struct Currency
	{
		int currency_id;
		int quantity;
	};

	std::vector<Currency> GetReceivingCurrency() const;
	std::vector<Currency> GetSendingCurrency() const;
	ArrayWrapper<OnlineProductWrapper> GetReceivingProducts();
	ArrayWrapper<OnlineProductWrapper> GetSendingProducts();
	bool IsNull();
	explicit operator bool();

private:
	PIMPL
};