#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ObjectWrapper.h"
class UnrealStringWrapper;
class ActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT ReplayWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ReplayWrapper)

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetReplayName();
	int GetEngineVersion();
	void SetEngineVersion(int newEngineVersion);
	int GetLicenseeVersion();
	void SetLicenseeVersion(int newLicenseeVersion);
	int GetNetVersion();
	void SetNetVersion(int newNetVersion);
	int GetReplayVersion();
	void SetReplayVersion(int newReplayVersion);
	int GetGameVersion();
	void SetGameVersion(int newGameVersion);
	int GetBuildID();
	void SetBuildID(int newBuildID);
	int GetChangelist();
	void SetChangelist(int newChangelist);
	UnrealStringWrapper GetBuildVersion();
	float GetRecordFPS();
	void SetRecordFPS(float newRecordFPS);
	float GetKeyframeDelay();
	void SetKeyframeDelay(float newKeyframeDelay);
	int GetMaxChannels();
	void SetMaxChannels(int newMaxChannels);
	int GetMaxReplaySizeMB();
	void SetMaxReplaySizeMB(int newMaxReplaySizeMB);
	UnrealStringWrapper GetFilename();
	UnrealStringWrapper GetId();
	UnrealStringWrapper GetDate();
	int GetNumFrames();
	void SetNumFrames(int newNumFrames);
	UnrealStringWrapper GetPlayerName();
	unsigned long GetbFileCorrupted();
	void SetbFileCorrupted(unsigned long newbFileCorrupted);
	unsigned long GetbForceKeyframe();
	void SetbForceKeyframe(unsigned long newbForceKeyframe);
	unsigned long GetbLoadedNetPackages();
	void SetbLoadedNetPackages(unsigned long newbLoadedNetPackages);
	unsigned long GetbDebug();
	void SetbDebug(unsigned long newbDebug);
	unsigned char GetReplayState();
	void SetReplayState(unsigned char newReplayState);
	int GetCurrentFrame();
	void SetCurrentFrame(int newCurrentFrame);
	int GetNextKeyframe();
	void SetNextKeyframe(int newNextKeyframe);
	float GetCurrentTime();
	void SetCurrentTime(float newCurrentTime);
	float GetAccumulatedDeltaTime();
	void SetAccumulatedDeltaTime(float newAccumulatedDeltaTime);
	float GetTimeToSkipTo();
	void SetTimeToSkipTo(float newTimeToSkipTo);
	int GetFrameToSkipTo();
	void SetFrameToSkipTo(int newFrameToSkipTo);
	int GetPlayersOnlyTicks();
	void SetPlayersOnlyTicks(int newPlayersOnlyTicks);

	//AUTO-GENERATED FUNCTION PROXIES
	bool IsFromBeforeGameVersion(unsigned char BeforeGameVersion);
	bool IsFromBeforeReplayVersion(unsigned char BeforeReplayVersion);
	void RemoveTimelineKeyframe(int KeyframeIndex);
	void eventTrimData(int FirstKeyframe, int FirstFrame);
	ReplayWrapper CreateCopy(float StartTime);
	void SkipToFrame(int frame, unsigned long bFlush);
	void SkipToTime(float Time, unsigned long bFlush);
	float GetReplayTimeSeconds();
	void StopPlayback();
	void StartPlaybackAtFrame(int StartFrame);
	void StartPlaybackAtTimeSeconds(float StartTime);
	void StopRecord();
	void StartRecord();
	void Tick2(float DeltaTime);
	void eventPreExport();
	void EventPlayedFrame(ReplayWrapper Replay);
	void EventPostTimeSkip(ReplayWrapper Replay);
	void EventPreTimeSkip(ReplayWrapper Replay);
	void EventSpawned(ReplayWrapper Replay, ActorWrapper A);
	void EventPlaybackStopped(ReplayWrapper Replay);
private:
	PIMPL
};