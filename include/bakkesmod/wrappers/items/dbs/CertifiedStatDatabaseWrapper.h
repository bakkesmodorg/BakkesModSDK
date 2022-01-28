#pragma once
#include "../../Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT CertifiedStatDatabaseWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(CertifiedStatDatabaseWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	std::string GetStatName(int32_t StatId);
	int32_t GetStatId(std::string& StatName);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};