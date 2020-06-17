#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_QualityWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_QualityWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	unsigned char GetQuality();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	UnrealStringWrapper ProductQualityToString(unsigned char InQuality);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};