#pragma once

class BAKKESMOD_PLUGIN_IMPORT ProductAssetWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(ProductAssetWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD ProductWrapper GetProduct() const;

private:
	PIMPL
	
};
