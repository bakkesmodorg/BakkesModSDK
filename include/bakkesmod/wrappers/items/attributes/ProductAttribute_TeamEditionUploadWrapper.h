#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_TeamEditionUploadWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_TeamEditionUploadWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	ArrayWrapper<int> GetSupportedTeamEditions();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};