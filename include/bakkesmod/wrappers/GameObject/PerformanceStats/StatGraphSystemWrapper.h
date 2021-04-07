#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class StatGraphWrapper;
class PerfStatGraphWrapper;
class InputBufferGraphWrapper;
class NetStatGraphWrapper;

class BAKKESMOD_PLUGIN_IMPORT StatGraphSystemWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(StatGraphSystemWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	float GetGraphSampleTime();
	void SetGraphSampleTime(float newGraphSampleTime);
	unsigned char GetGraphLevel();
	void SetGraphLevel(unsigned char newGraphLevel);
	PerfStatGraphWrapper GetPerfStatGraph();
	void SetPerfStatGraph(PerfStatGraphWrapper newPerfStatGraph);
	NetStatGraphWrapper GetNetStatGraph();
	void SetNetStatGraph(NetStatGraphWrapper newNetStatGraph);
	InputBufferGraphWrapper GetInputBufferGraph();
	void SetInputBufferGraph(InputBufferGraphWrapper newInputBufferGraph);
	ArrayWrapper<StatGraphWrapper> GetStatGraphs();
	ArrayWrapper<StatGraphWrapper> GetVisibleStatGraphs();
	int GetPreallocGraphLines();
	void SetPreallocGraphLines(int newPreallocGraphLines);

	//AUTO-GENERATED FUNCTION PROXIES
	void __StatGraphSystem_TA__SetGraphLevel(StatGraphWrapper G);
	void PacketReceived(float Latency);
	void Graphtime(float Seconds);
	void StatGraphNext();
	float GetGraphSampleTime2(unsigned char Level);
	void SetGraphLevel2(unsigned char Level);
private:
	PIMPL
};