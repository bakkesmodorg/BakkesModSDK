#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/PerformanceStats/StatGraphWrapper.h"
class SampleHistoryWrapper;

class BAKKESMOD_PLUGIN_IMPORT NetStatGraphWrapper : public StatGraphWrapper {
public:
	CONSTRUCTORS(NetStatGraphWrapper)

	//AUTO-GENERATED FROM FIELDS
	SampleHistoryWrapper GetPacketsOut();
	void SetPacketsOut(SampleHistoryWrapper newPacketsOut);
	SampleHistoryWrapper GetPacketsIn();
	void SetPacketsIn(SampleHistoryWrapper newPacketsIn);
	SampleHistoryWrapper GetLostPacketsOut();
	void SetLostPacketsOut(SampleHistoryWrapper newLostPacketsOut);
	SampleHistoryWrapper GetLostPacketsIn();
	void SetLostPacketsIn(SampleHistoryWrapper newLostPacketsIn);
	SampleHistoryWrapper GetBytesOut();
	void SetBytesOut(SampleHistoryWrapper newBytesOut);
	SampleHistoryWrapper GetBytesIn();
	void SetBytesIn(SampleHistoryWrapper newBytesIn);
	SampleHistoryWrapper GetLatency();
	void SetLatency(SampleHistoryWrapper newLatency);
	float GetExpectedOutPacketRate();
	void SetExpectedOutPacketRate(float newExpectedOutPacketRate);
	float GetExpectedInPacketRate();
	void SetExpectedInPacketRate(float newExpectedInPacketRate);
	float GetMaxBytesRate();
	void SetMaxBytesRate(float newMaxBytesRate);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventUpdateGraphRanges();
	SampleHistoryWrapper CreateBytesSummary(std::string Title);
	SampleHistoryWrapper CreateLossSummary(std::string Title);
	SampleHistoryWrapper CreatePktSummary(std::string Title);
	void eventConstruct();
private:
	PIMPL
};