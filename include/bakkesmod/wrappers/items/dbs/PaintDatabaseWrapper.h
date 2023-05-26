#pragma once
#include "../../Engine/ObjectWrapper.h"
#include "ProductPaintWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT PaintDatabaseWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(PaintDatabaseWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	_NODISCARD ArrayWrapper<ProductPaintWrapper> GetPaints() const;

	_NODISCARD bool AddCustomPaintColor(const std::string& name, const LinearColor& color);
	_NODISCARD bool UpdateCustomPaintColor(const std::string& name, const LinearColor& color);

	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	std::string GetPaintName(int PaintID);
	int GetPaintID(std::string& PaintName);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};