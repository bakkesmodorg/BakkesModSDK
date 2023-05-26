#pragma once

class BAKKESMOD_PLUGIN_IMPORT ProductEquipProfileWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(ProductEquipProfileWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD std::vector<int> GetForcedProducts() const;
	_NODISCARD std::vector<int> GetDefaultProducts() const;
	_NODISCARD bool CanEquip(const ProductWrapper& product_wrappper) const;

private:
	PIMPL
	
};
