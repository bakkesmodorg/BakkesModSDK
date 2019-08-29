#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/PerformanceStats/StatGraphWrapper.h"
class SampleHistoryWrapper;

class BAKKESMOD_PLUGIN_IMPORT PerfStatGraphWrapper : public StatGraphWrapper {
public:
	CONSTRUCTORS(PerfStatGraphWrapper)

	//AUTO-GENERATED FROM FIELDS
	SampleHistoryWrapper GetFPS();
	void SetFPS(SampleHistoryWrapper newFPS);
	SampleHistoryWrapper GetFrameTime();
	void SetFrameTime(SampleHistoryWrapper newFrameTime);
	SampleHistoryWrapper GetGameThreadTime();
	void SetGameThreadTime(SampleHistoryWrapper newGameThreadTime);
	SampleHistoryWrapper GetRenderThreadTime();
	void SetRenderThreadTime(SampleHistoryWrapper newRenderThreadTime);
	SampleHistoryWrapper GetGPUFrameTime();
	void SetGPUFrameTime(SampleHistoryWrapper newGPUFrameTime);
	ArrayWrapper<SampleHistoryWrapper> GetFrameTimeHistories();
	float GetMaxFPS();
	void SetMaxFPS(float newMaxFPS);
	float GetTargetFPS();
	void SetTargetFPS(float newTargetFPS);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventUpdateGraphRanges();
	SampleHistoryWrapper CreateFrameTimeHistory(std::string Title);
	SampleHistoryWrapper CreateFpsHistory(std::string Title);
	void eventConstruct();
private:
	PIMPL
};