#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT SampleRecordSettingsWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(SampleRecordSettingsWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	float GetMaxSampleAge();
	void SetMaxSampleAge(float newMaxSampleAge);
	float GetRecordRate();
	void SetRecordRate(float newRecordRate);

	//AUTO-GENERATED FUNCTION PROXIES
private:
	PIMPL
};