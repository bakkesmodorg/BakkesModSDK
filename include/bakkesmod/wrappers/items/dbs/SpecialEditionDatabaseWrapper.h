#pragma once
#include "../../Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT SpecialEditionDatabaseWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(SpecialEditionDatabaseWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	std::string GetSpecialEditionName(int EditionID);
	int GetSpecialEditionId(std::string& EditionName);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};