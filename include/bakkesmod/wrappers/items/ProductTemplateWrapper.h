#pragma once
#include "../Engine/ObjectWrapper.h"
class ProductWrapper;
class ProductSlotWrapper;



class BAKKESMOD_PLUGIN_IMPORT ProductTemplateWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ProductTemplateWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	ProductSlotWrapper GetSlot();
	unsigned char GetUnlockMethod(); // see wrapper structs for the enum
	unsigned char GetQuality(); // see wrapper structs for the enum
	ProductWrapper GetRequiredProduct();
	unsigned long GetbLicensed();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};