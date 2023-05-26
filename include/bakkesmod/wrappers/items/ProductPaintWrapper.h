#pragma once

class BAKKESMOD_PLUGIN_IMPORT ProductPaintWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(ProductPaintWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	_NODISCARD  std::string GetLabel() const;
	_NODISCARD  bool GetbVisible() const;

	_NODISCARD int GetId() const;

	/**
	 * \brief Use EnumWrapper::GetPaintFinishTyp() to interpret this value
	 * \return A enum value for the WeatherVariant
	 */
	_NODISCARD unsigned char GetFinishType() const;
	_NODISCARD std::vector<LinearColor> GetColors() const;
	//END SELF IMPLEMENTED

private:
	PIMPL
	
};
