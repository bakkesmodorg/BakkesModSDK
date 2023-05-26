#pragma once

class BAKKESMOD_PLUGIN_IMPORT MapDataWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(MapDataWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD std::string GetName() const;
	_NODISCARD std::string GetLocalizedName() const;
	_NODISCARD std::string GetLocalizedVariantName() const;
	MapDataWrapper GetIsVariantOf() const;

	/**
	 * \brief Use EnumWrapper::GetWeatherVariant to interpret this value
	 * \return A enum value for the WeatherVariant
	 */
	_NODISCARD unsigned char GetWeatherVariant() const;

private:
	PIMPL
	
};
