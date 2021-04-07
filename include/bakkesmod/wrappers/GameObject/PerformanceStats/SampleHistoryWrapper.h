#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class SampleRecordSettingsWrapper;
class WrapperStructs;
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT SampleHistoryWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(SampleHistoryWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	SampleRecordSettingsWrapper GetRecordSettings();
	void SetRecordSettings(SampleRecordSettingsWrapper newRecordSettings);
	UnrealStringWrapper GetTitle();
	float GetYMin();
	void SetYMin(float newYMin);
	float GetYMax();
	void SetYMax(float newYMax);
	float GetGoodValue();
	void SetGoodValue(float newGoodValue);
	float GetBadValue();
	void SetBadValue(float newBadValue);
	float GetBaseValue();
	void SetBaseValue(float newBaseValue);
	StructArrayWrapper<RecordedSample> GetSamples();
	int GetSampleIndex();
	void SetSampleIndex(int newSampleIndex);
	float GetAccumTime();
	void SetAccumTime(float newAccumTime);
	RecordedSample GetPendingSample();
	void SetPendingSample(RecordedSample newPendingSample);
	unsigned long GetbHasPendingSample();
	void SetbHasPendingSample(unsigned long newbHasPendingSample);

	//AUTO-GENERATED FUNCTION PROXIES
	void Tick(float DeltaTime);
	void AddSample(float NewValue);
	float GetSummaryValue(unsigned char Type, float MaxSampleAge, unsigned long bAbsoluteValue);
	SampleHistoryWrapper SetBaseValue2(float InBaseValue);
	SampleHistoryWrapper SetGoodBadValues(float InGoodValue, float InBadValue);
	SampleHistoryWrapper SetGraphMaxMin(float MaxValue, float MinValue);
	SampleHistoryWrapper SetTitle(std::string InTitle);
private:
	PIMPL
};