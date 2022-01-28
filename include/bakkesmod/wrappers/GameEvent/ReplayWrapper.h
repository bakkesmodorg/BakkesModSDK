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
	int32_t GetEngineVersion();
	void SetEngineVersion(int32_t newEngineVersion);
	int32_t GetLicenseeVersion();
	void SetLicenseeVersion(int32_t newLicenseeVersion);
	int32_t GetNetVersion();
	void SetNetVersion(int32_t newNetVersion);
	int32_t GetReplayVersion();
	void SetReplayVersion(int32_t newReplayVersion);
	int32_t GetReplayLastSaveVersion();
	void SetReplayLastSaveVersion(int32_t newReplayLastSaveVersion);
	int32_t GetGameVersion();
	void SetGameVersion(int32_t newGameVersion);
	int32_t GetBuildID();
	void SetBuildID(int32_t newBuildID);
	int32_t GetChangelist();
	void SetChangelist(int32_t newChangelist);
	UnrealStringWrapper GetBuildVersion();
	int32_t GetReserveMegabytes();
	void SetReserveMegabytes(int32_t newReserveMegabytes);
	float GetRecordFPS();
	void SetRecordFPS(float newRecordFPS);
	float GetKeyframeDelay();
	void SetKeyframeDelay(float newKeyframeDelay);
	int32_t GetMaxChannels();
	void SetMaxChannels(int32_t newMaxChannels);
	int32_t GetMaxReplaySizeMB();
	void SetMaxReplaySizeMB(int32_t newMaxReplaySizeMB);
	UnrealStringWrapper GetFilename();
	UnrealStringWrapper GetId();
	UnrealStringWrapper GetDate();
	int32_t GetNumFrames();
	void SetNumFrames(int32_t newNumFrames);
	UnrealStringWrapper GetPlayerName();
	unsigned long GetbFileCorrupted();
	void SetbFileCorrupted(unsigned long newbFileCorrupted);
	unsigned long GetbForceKeyframe();
	void SetbForceKeyframe(unsigned long newbForceKeyframe);
	unsigned long GetbLoadedNetPackages();
	void SetbLoadedNetPackages(unsigned long newbLoadedNetPackages);
	unsigned long GetbDebug();
	void SetbDebug(unsigned long newbDebug);
	uint8_t GetReplayState();
	void SetReplayState(uint8_t newReplayState);
	int32_t GetCurrentFrame();
	void SetCurrentFrame(int32_t newCurrentFrame);
	int32_t GetNextKeyframe();
	void SetNextKeyframe(int32_t newNextKeyframe);
	float GetCurrentTime();
	void SetCurrentTime(float newCurrentTime);
	float GetAccumulatedDeltaTime();
	void SetAccumulatedDeltaTime(float newAccumulatedDeltaTime);
	float GetTimeToSkipTo();
	void SetTimeToSkipTo(float newTimeToSkipTo);
	int32_t GetFrameToSkipTo();
	void SetFrameToSkipTo(int32_t newFrameToSkipTo);
	int32_t GetPlayersOnlyTicks();
	void SetPlayersOnlyTicks(int32_t newPlayersOnlyTicks);

	//AUTO-GENERATED FUNCTION PROXIES
	float GetPlaybackTime();
	bool IsFromBeforeGameVersion(uint8_t BeforeGameVersion);
	bool IsFromBeforeReplayVersion(uint8_t BeforeReplayVersion);
	void SetReplayName(std::string NewName);
	void RemoveTimelineKeyframe(int32_t KeyframeIndex);
	void eventTrimData(int32_t FirstKeyframe, int32_t FirstFrame);
	ReplayWrapper CreateCopy(float StartTime);
	void ImportReplay(std::string Path);
	void ExportReplay(std::string Path);
#ifdef __cpp_lib_filesystem
	void ImportReplay(std::filesystem::path Path);
	void ExportReplay(std::filesystem::path Path);
#endif


	void SkipToFrame(int32_t frame, unsigned long bFlush);
	void SkipToTime(float Time, unsigned long bFlush);
	float GetReplayTimeSeconds();
	void StopPlayback();
	void StartPlaybackAtFrame(int32_t StartFrame);
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