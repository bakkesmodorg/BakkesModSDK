#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_SpecialEditionWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_SpecialEditionWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int GetEditionID();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	UnrealStringWrapper GetSortLabel();
	int GetOverrideProductID(int ProductID);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};