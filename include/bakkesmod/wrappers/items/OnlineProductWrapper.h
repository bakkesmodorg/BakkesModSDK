#pragma once
#include "../Engine/ObjectWrapper.h"
#include "../Engine/UnrealStringWrapper.h"
#include "../arraywrapper.h"
class ProductWrapper;
class ProductAttributeWrapper;


class BAKKESMOD_PLUGIN_IMPORT OnlineProductWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(OnlineProductWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	std::string SeriesIdToSeriesName(int32_t seriesID);
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int32_t GetProductID();
	int32_t GetSeriesID();
	int32_t GetTradeHold(); // Se wrapperstructs for the enum
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	std::string GetProductSeries();
	uint8_t GetQuality();
	ArrayWrapper<ProductAttributeWrapper> GetAttributes();
	UnrealStringWrapper GetLongLabel();
	int32_t GetBlueprintSeriesID();
	uint8_t GetBlueprintType();
	bool IsBlueprint();
	ProductWrapper GetProduct();
	bool GetIsUntradable();
	uint64_t GetInstanceID();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};