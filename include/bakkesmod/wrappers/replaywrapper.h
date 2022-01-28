#pragma once
#include "./GameEvent/ServerWrapper.h"
class BAKKESMOD_PLUGIN_IMPORT ReplayWrapper : public ServerWrapper
{
public:
	ReplayWrapper(std::uintptr_t server, std::uintptr_t gameinfo, std::uintptr_t replaydirector);
	ReplayWrapper(const ReplayWrapper& other);
	ReplayWrapper& operator=(ReplayWrapper rhs);
	~ReplayWrapper();
	ActorWrapper GetViewTarget();
	float GetReplayTimeElapsed();
	int32_t GetReplayFPS();
	int32_t GetCurrentReplayFrame();
	void AddKeyFrame(int32_t frame, string name);
	void RemoveKeyFrame(int32_t frame);
	void SkipToFrame(int32_t frame);
	void SkipToTime(float time);
	
	void StartPlaybackAtFrame(int32_t frame);
	void StartPlaybackAtTime(float time);
private:
	PIMPL
};