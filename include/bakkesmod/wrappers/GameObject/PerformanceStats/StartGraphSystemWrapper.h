#pragma once
template<class T> class ArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"
class InputBufferGraphWrapper;
class NetStatGraphWrapper;
class PerfStatGraphWrapper;
class StatGraphWrapper;

class BAKKESMOD_PLUGIN_IMPORT StartGraphSystemWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(StartGraphSystemWrapper)

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

	//AUTO-GENERATED FUNCTION PROXIES
	void Graphtime(float Seconds);
	void StatGraphNext();
	float GetGraphSampleTime2(unsigned char Level);
	void SetGraphLevel2(unsigned char Level);
private:
	PIMPL
};