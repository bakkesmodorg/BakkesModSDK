#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_PaintedWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_PaintedWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int GetPaintID();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	UnrealStringWrapper GetSortLabel();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};