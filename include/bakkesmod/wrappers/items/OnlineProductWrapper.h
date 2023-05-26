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
	std::string SeriesIdToSeriesName(int seriesID);
	_NODISCARD bool IsFavorited() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int GetProductID();
	int GetSeriesID();
	int GetTradeHold(); // Se wrapperstructs for the enum
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	std::string GetProductSeries();
	unsigned char GetQuality();
	ArrayWrapper<ProductAttributeWrapper> GetAttributes();
	UnrealStringWrapper GetLongLabel();
	int GetBlueprintSeriesID();
	unsigned char GetBlueprintType();
	bool IsBlueprint();
	ProductWrapper GetProduct();
	bool GetIsUntradable();
	[[deprecated("Missing half the data. Use GetInstanceIDV2")]]
	unsigned long long GetInstanceID();
	_NODISCARD ProductInstanceID GetInstanceIDV2();
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};