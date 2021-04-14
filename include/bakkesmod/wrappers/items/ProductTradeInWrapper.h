#pragma once
#include "bakkesmod/wrappers/Engine/ObjectWrapper.h"
#include "bakkesmod/wrappers/arraywrapper.h"
#include "OnlineProductWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductTradeInWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ProductTradeInWrapper)

	ArrayWrapper<OnlineProductWrapper> GetProducts() const;
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

private:
	PIMPL
};