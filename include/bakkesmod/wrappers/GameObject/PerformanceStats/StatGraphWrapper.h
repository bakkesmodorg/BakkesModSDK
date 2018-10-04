#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class SampleHistoryWrapper;
class SampleRecordSettingsWrapper;

class BAKKESMOD_PLUGIN_IMPORT StatGraphWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(StatGraphWrapper)

	//AUTO-GENERATED FROM FIELDS
	SampleRecordSettingsWrapper GetRecordSettings();
	void SetRecordSettings(SampleRecordSettingsWrapper newRecordSettings);
	double GetLastTickTime();
	void SetLastTickTime(double newLastTickTime);
	ArrayWrapper<SampleHistoryWrapper> GetSampleHistories();

	//AUTO-GENERATED FUNCTION PROXIES
	SampleHistoryWrapper AddSampleHistory(SampleHistoryWrapper History);
	void eventConstruct();
private:
	PIMPL
};