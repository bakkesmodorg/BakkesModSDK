#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ObjectWrapper.h"
class ActorWrapper;
class UnrealStringWrapper;
#ifdef __cpp_lib_filesystem
#include <filesystem>
#endif
#undef GetCurrentTime

class BAKKESMOD_PLUGIN_IMPORT ReplayWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(ReplayWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

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
	int GetReplayLastSaveVersion();
	void SetReplayLastSaveVersion(int newReplayLastSaveVersion);
	int GetGameVersion();
	void SetGameVersion(int newGameVersion);
	int GetBuildID();
	void SetBuildID(int newBuildID);
	int GetChangelist();
	void SetChangelist(int newChangelist);
	UnrealStringWrapper GetBuildVersion();
	int GetReserveMegabytes();
	void SetReserveMegabytes(int newReserveMegabytes);
	float GetRecordFPS();
	void SetRecordFPS(float newRecordFPS);
	float GetKeyframeDelay();
	void SetKeyframeDelay(float newKeyframeDelay);
	int GetMaxChannels();
	void SetMaxChannels(int newMaxChannels);
	int GetMaxReplaySizeMB();
	void SetMaxReplaySizeMB(int newMaxReplaySizeMB);
	[[deprecated("Removed from Rocket League, returns the same as GetId")]]
	UnrealStringWrapper GetFilename();
	_NODISCARD UnrealStringWrapper GetFilePath() const;
	UnrealStringWrapper GetId();
	UnrealStringWrapper GetDate();
	std::string GetMapName() const;
	int GetNumFrames();
	void SetNumFrames(int newNumFrames);
	std::string GetMatchType() const;
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
	float GetPlaybackTime();
	bool IsFromBeforeGameVersion(unsigned char BeforeGameVersion);
	bool IsFromBeforeReplayVersion(unsigned char BeforeReplayVersion);
	void SetReplayName(std::string NewName);
	void RemoveTimelineKeyframe(int KeyframeIndex);
	void eventTrimData(int FirstKeyframe, int FirstFrame);
	ReplayWrapper CreateCopy(float StartTime);
	void ImportReplay(std::string Path);
	void ExportReplay(std::string Path);
#ifdef __cpp_lib_filesystem
	void ImportReplay(std::filesystem::path Path);
	void ExportReplay(std::filesystem::path Path);
#endif


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