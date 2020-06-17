#pragma once
#include "ProductAttributeWrapper.h"

class ProductWrapper;

class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_BodyCompatibilityWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_BodyCompatibilityWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	ArrayWrapper<ProductWrapper> GetCompatibleBodies();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};