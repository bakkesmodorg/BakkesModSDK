#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ObjectWrapper.h"
class UnrealStringWrapper;
class StatGraphSystemWrapper;

class BAKKESMOD_PLUGIN_IMPORT EngineTAWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(EngineTAWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbEnableClientPrediction();
	void SetbEnableClientPrediction(unsigned long newbEnableClientPrediction);
	unsigned long GetbClientPhysicsUpdate();
	void SetbClientPhysicsUpdate(unsigned long newbClientPhysicsUpdate);
	unsigned long GetbDisableClientCorrections();
	void SetbDisableClientCorrections(unsigned long newbDisableClientCorrections);
	unsigned long GetbDebugClientCorrections();
	void SetbDebugClientCorrections(unsigned long newbDebugClientCorrections);
	unsigned long GetbForceClientCorrection();
	void SetbForceClientCorrection(unsigned long newbForceClientCorrection);
	float GetPhysicsFramerate();
	void SetPhysicsFramerate(float newPhysicsFramerate);
	int32_t GetMaxPhysicsSubsteps();
	void SetMaxPhysicsSubsteps(int32_t newMaxPhysicsSubsteps);
	int32_t GetMaxUploadedClientFrames();
	void SetMaxUploadedClientFrames(int32_t newMaxUploadedClientFrames);
	int32_t GetMaxClientReplayFrames();
	void SetMaxClientReplayFrames(int32_t newMaxClientReplayFrames);
	int32_t GetPhysicsFrame();
	void SetPhysicsFrame(int32_t newPhysicsFrame);
	float GetRenderAlpha();
	void SetRenderAlpha(float newRenderAlpha);
	int32_t GetReplicatedPhysicsFrame();
	void SetReplicatedPhysicsFrame(int32_t newReplicatedPhysicsFrame);
	int32_t GetDirtyPhysicsFrame();
	void SetDirtyPhysicsFrame(int32_t newDirtyPhysicsFrame);
	int32_t GetForceCorrectionFrames();
	void SetForceCorrectionFrames(int32_t newForceCorrectionFrames);
	int32_t GetTickNotifyIndex();
	void SetTickNotifyIndex(int32_t newTickNotifyIndex);
	UnrealStringWrapper GetShellArchetypePath();
	float GetLastBugReportTime();
	void SetLastBugReportTime(float newLastBugReportTime);
	float GetDebugClientCorrectionStartTime();
	void SetDebugClientCorrectionStartTime(float newDebugClientCorrectionStartTime);
	int32_t GetDebugClientCorrectionCount();
	void SetDebugClientCorrectionCount(int32_t newDebugClientCorrectionCount);
	StatGraphSystemWrapper GetStatGraphs();
	void SetStatGraphs(StatGraphSystemWrapper newStatGraphs);
	float GetLastPhysicsDeltaTimeScale();
	void SetLastPhysicsDeltaTimeScale(float newLastPhysicsDeltaTimeScale);

	//AUTO-GENERATED FUNCTION PROXIES
	void DebugClientCorrections2();
	float GetBulletFixedDeltaTime();
	void RunPhysicsStep(int32_t BulletSceneIndex, float DeltaTime);
	void UpdateReplicatedPhysicsFrame(int32_t ServerFrame);
	void DebugDedicatedServer(float ForHowLong);
	float GetPhysicsTime();
	void eventRecordAppStart();
	void eventInit();
	void EventPreAsyncTick(float DeltaTime);
private:
	PIMPL
};