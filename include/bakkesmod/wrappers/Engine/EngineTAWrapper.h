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

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbEnableClientPrediction();
	void SetbEnableClientPrediction(unsigned long newbEnableClientPrediction);
	unsigned long GetbClientPhysicsUpdate();
	void SetbClientPhysicsUpdate(unsigned long newbClientPhysicsUpdate);
	unsigned long GetbDisableClientCorrections();
	void SetbDisableClientCorrections(unsigned long newbDisableClientCorrections);
	unsigned long GetbColorBlind();
	void SetbColorBlind(unsigned long newbColorBlind);
	unsigned long GetbDebugClientCorrections();
	void SetbDebugClientCorrections(unsigned long newbDebugClientCorrections);
	unsigned long GetbForceClientCorrection();
	void SetbForceClientCorrection(unsigned long newbForceClientCorrection);
	unsigned long GetbDebugSimTimeScale();
	void SetbDebugSimTimeScale(unsigned long newbDebugSimTimeScale);
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

	//AUTO-GENERATED FUNCTION PROXIES
	bool UseSimTimeScaling();
	void DebugClientCorrections2();
	void SetColorBlind(unsigned long bIsColorBlind);
	float GetExtraSimTime(float DeltaTime, float ExtraTimeRemaining);
	void UpdateAdjustedSimTime(int FrameAdjustment);
	float GetBulletFixedDeltaTime();
	void RunPhysicsStep(int BulletSceneIndex, float DeltaTime);
	void UpdateReplicatedPhysicsFrame(int ServerFrame, float Ping);
	void DebugDedicatedServer(float ForHowLong);
	float GetPhysicsTime();
	void eventRecordAppStart();
	void eventInit();
	void EventAdjustSimTimeFinished();
	void EventColorBlindChanged();
	void EventPreAsyncTick(float DeltaTime);
private:
	PIMPL
};