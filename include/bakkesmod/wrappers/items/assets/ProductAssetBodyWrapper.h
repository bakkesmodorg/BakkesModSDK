#pragma once
#include "ProductEquipProfileWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT ProductAssetBodyWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(ProductAssetBodyWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD ProductEquipProfileWrapper GetEquipProfile() const;
	_NODISCARD bool CanEquip(const ProductWrapper& product_wrappper) const;

private:
	PIMPL
	
};
