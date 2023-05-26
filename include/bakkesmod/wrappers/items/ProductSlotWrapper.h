#pragma once
#include "../Engine/ObjectWrapper.h"
#include "../Engine/UnrealStringWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT ProductSlotWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ProductSlotWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	ProductWrapper GetDefaultProduct() const;
	UnrealStringWrapper GetLabel();
	UnrealStringWrapper GetPluralLabel();
	UnrealStringWrapper GetDescription();
	UnrealStringWrapper GetOnlineLabel();
	int GetSlotIndex();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};