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
	SampleHistoryWrapper GetBufferTarget();
	void SetBufferTarget(SampleHistoryWrapper newBufferTarget);
	SampleHistoryWrapper GetOverUnderFrames();
	void SetOverUnderFrames(SampleHistoryWrapper newOverUnderFrames);
	SampleHistoryWrapper GetPhysicsRate();
	void SetPhysicsRate(SampleHistoryWrapper newPhysicsRate);
	float GetMaxPhysicsRate();
	void SetMaxPhysicsRate(float newMaxPhysicsRate);
	float GetMinPhysicsRate();
	void SetMinPhysicsRate(float newMinPhysicsRate);

	//AUTO-GENERATED FUNCTION PROXIES
	SampleHistoryWrapper CreateBufferHistory(std::string Title);
	void eventConstruct();
private:
	PIMPL
};