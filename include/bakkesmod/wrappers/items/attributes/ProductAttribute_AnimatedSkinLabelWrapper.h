#pragma once
#include "ProductAttributeWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_AnimatedSkinLabelWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_AnimatedSkinLabelWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetAnimatedLabel();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};