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
	int GetMaxPhysicsSubsteps();
	void SetMaxPhysicsSubsteps(int newMaxPhysicsSubsteps);
	int GetMaxUploadedClientFrames();
	void SetMaxUploadedClientFrames(int newMaxUploadedClientFrames);
	int GetMaxClientReplayFrames();
	void SetMaxClientReplayFrames(int newMaxClientReplayFrames);
	int GetPhysicsFrame();
	void SetPhysicsFrame(int newPhysicsFrame);
	float GetRenderAlpha();
	void SetRenderAlpha(float newRenderAlpha);
	int GetReplicatedPhysicsFrame();
	void SetReplicatedPhysicsFrame(int newReplicatedPhysicsFrame);
	int GetDirtyPhysicsFrame();
	void SetDirtyPhysicsFrame(int newDirtyPhysicsFrame);
	int GetForceCorrectionFrames();
	void SetForceCorrectionFrames(int newForceCorrectionFrames);
	int GetTickNotifyIndex();
	void SetTickNotifyIndex(int newTickNotifyIndex);
	UnrealStringWrapper GetShellArchetypePath();
	float GetLastBugReportTime();
	void SetLastBugReportTime(float newLastBugReportTime);
	float GetDebugClientCorrectionStartTime();
	void SetDebugClientCorrectionStartTime(float newDebugClientCorrectionStartTime);
	int GetDebugClientCorrectionCount();
	void SetDebugClientCorrectionCount(int newDebugClientCorrectionCount);
	StatGraphSystemWrapper GetStatGraphs();
	void SetStatGraphs(StatGraphSystemWrapper newStatGraphs);
	float GetLastPhysicsDeltaTimeScale();
	void SetLastPhysicsDeltaTimeScale(float newLastPhysicsDeltaTimeScale);

	//AUTO-GENERATED FUNCTION PROXIES
	void DebugClientCorrections2();
	float GetBulletFixedDeltaTime();
	void RunPhysicsStep(int BulletSceneIndex, float DeltaTime);
	void UpdateReplicatedPhysicsFrame(int ServerFrame);
	void DebugDedicatedServer(float ForHowLong);
	float GetPhysicsTime();
	void eventRecordAppStart();
	void eventInit();
	void EventPreAsyncTick(float DeltaTime);
private:
	PIMPL
};