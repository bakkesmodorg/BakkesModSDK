#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_BlueprintWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_BlueprintWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int GetProductID();
	int GetCachedBlueprintSeriesID();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	UnrealStringWrapper GetSortLabel();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};