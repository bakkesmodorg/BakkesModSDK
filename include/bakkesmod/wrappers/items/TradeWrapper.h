#pragma once
#include "../Engine/ObjectWrapper.h"
#include "OnlineProductWrapper.h"



class BAKKESMOD_PLUGIN_IMPORT TradeWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(TradeWrapper)

	struct Currency
	{
		int32_t currency_id;
		int32_t quantity;
	};

	std::vector<Currency> GetReceivingCurrency() const;
	std::vector<Currency> GetSendingCurrency() const;
	ArrayWrapper<OnlineProductWrapper> GetReceivingProducts();
	ArrayWrapper<OnlineProductWrapper> GetSendingProducts();
	UniqueIDWrapper GetTradingPlayer() const;
	GUIDWrapper GetTradeGuid() const;
	bool IsNull();
	explicit operator bool();

private:
	PIMPL
};