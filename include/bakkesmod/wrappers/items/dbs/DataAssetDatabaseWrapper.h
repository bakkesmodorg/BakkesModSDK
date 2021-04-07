#pragma once
#include "../../Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT DataAssetDatabaseWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(DataAssetDatabaseWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	std::string GetName(int DataAssetID);
	int GetID(std::string& DataAssetName);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};