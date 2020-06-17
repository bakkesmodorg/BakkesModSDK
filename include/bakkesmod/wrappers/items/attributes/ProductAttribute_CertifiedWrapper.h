#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_CertifiedWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_CertifiedWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	std::string GetValueKeyName();
	int GetStatId();
	int GetStatValue();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	UnrealStringWrapper GetSortLabel();
	UnrealStringWrapper GetDescription();
	UnrealStringWrapper GetRankLabel();
	int GetRank();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};