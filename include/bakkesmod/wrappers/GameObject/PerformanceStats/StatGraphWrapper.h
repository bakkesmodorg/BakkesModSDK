#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class SampleRecordSettingsWrapper;
class SampleHistoryWrapper;

class BAKKESMOD_PLUGIN_IMPORT StatGraphWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(StatGraphWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	SampleRecordSettingsWrapper GetRecordSettings();
	void SetRecordSettings(SampleRecordSettingsWrapper newRecordSettings);
	double GetLastTickTime();
	void SetLastTickTime(double newLastTickTime);
	ArrayWrapper<SampleHistoryWrapper> GetSampleHistories();

	//AUTO-GENERATED FUNCTION PROXIES
	void StopDrawing();
	SampleHistoryWrapper CreateSampleHistory(std::string Title);
	SampleHistoryWrapper AddSampleHistory(SampleHistoryWrapper History);
	void eventConstruct();
private:
	PIMPL
};