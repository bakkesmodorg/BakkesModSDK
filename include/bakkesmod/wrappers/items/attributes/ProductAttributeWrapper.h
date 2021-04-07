#pragma once
#include "../../Engine/ObjectWrapper.h"
#include "../../Engine/UnrealStringWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT ProductAttributeWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ProductAttributeWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	std::string GetAttributeType();
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	std::string GetTypename();
	UnrealStringWrapper GetLabel();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};