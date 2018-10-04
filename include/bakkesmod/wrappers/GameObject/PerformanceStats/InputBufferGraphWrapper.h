#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/PerformanceStats/StatGraphWrapper.h"
class SampleHistoryWrapper;

class BAKKESMOD_PLUGIN_IMPORT InputBufferGraphWrapper : public StatGraphWrapper {
public:
	CONSTRUCTORS(InputBufferGraphWrapper)

	//AUTO-GENERATED FROM FIELDS
	SampleHistoryWrapper GetBuffer();
	void SetBuffer(SampleHistoryWrapper newBuffer);
	SampleHistoryWrapper GetBufferMax();
	void SetBufferMax(SampleHistoryWrapper newBufferMax);
	SampleHistoryWrapper GetOverUnderFrames();
	void SetOverUnderFrames(SampleHistoryWrapper newOverUnderFrames);
	SampleHistoryWrapper GetPhysicsRate();
	void SetPhysicsRate(SampleHistoryWrapper newPhysicsRate);
	float GetMaxPhysicsRate();
	void SetMaxPhysicsRate(float newMaxPhysicsRate);
	float GetMinPhysicsRate();
	void SetMinPhysicsRate(float newMinPhysicsRate);

	//AUTO-GENERATED FUNCTION PROXIES
	void AddSample(int InBufferLow, int InBufferHigh, int InBufferMax, int OverFrames, int UnderFrames);
	void eventConstruct();
private:
	PIMPL
};