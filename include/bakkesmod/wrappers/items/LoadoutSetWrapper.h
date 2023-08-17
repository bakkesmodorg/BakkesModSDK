#pragma once

#include "LoadoutWrapper.h"
#include "OnlineProductWrapper.h"
#include "wrapperstructs.h"

struct LoadoutSetData {
	LoadoutWrapper blue;
	LoadoutWrapper orange;
};


class BAKKESMOD_PLUGIN_IMPORT LoadoutSetWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(LoadoutSetWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	void CopyFrom(const LoadoutSetWrapper& other);
	_NODISCARD std::string GetName() const;
	void Rename(const std::string& new_name);
	void EquipProduct(const OnlineProductWrapper& online_product, int team);
	void EquipProduct(const ProductInstanceID& instance_id, int slot_id, int team);
	_NODISCARD LoadoutSetData GetLoadoutData() const;

private:
	PIMPL
};