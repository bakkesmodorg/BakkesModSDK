#pragma once
#include "ProductTemplateWrapper.h"
#include "../Engine/UnrealStringWrapper.h"
class ProductAttributeWrapper;

class BAKKESMOD_PLUGIN_IMPORT ProductWrapper : public ProductTemplateWrapper {
public:
	CONSTRUCTORS(ProductWrapper)

	//BEGIN SELF IMPLEMENTED
	bool IsNull();
	explicit operator bool();
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	std::string GetAssetPackageName();
	UnrealStringWrapper GetAssetPath();
	UnrealStringWrapper GetLabel();
	UnrealStringWrapper GetAsciiLabel();
	UnrealStringWrapper GetLongLabel();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	bool IsPaintable();
	UnrealStringWrapper GetDisplayLabelSlot();
	unsigned char GetQuality();
	bool IsContainerKey();
	bool IsCurrency();
	bool IsBlueprint();
	bool IsContainerUnlocked();
	bool IsContainer();
	bool IsSchematic();
	bool IsPlatformExclusive();
	bool IsLicensed();
	ArrayWrapper<ProductAttributeWrapper> GetAttributes();
	UnrealStringWrapper GetSortLabel();
	UnrealStringWrapper GetThumbnailAssetPath();
	UnrealStringWrapper GetThumbnailPackageNameForLoad();
	std::string GetThumbnailPackageName();
	std::string GetThumbnailAssetName();
	UnrealStringWrapper GetTrademarkLabel();
	int32_t GetID();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};