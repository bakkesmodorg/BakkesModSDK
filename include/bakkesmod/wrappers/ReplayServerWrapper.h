#pragma once
#include "./GameEvent/ServerWrapper.h"
class ReplayWrapper;
class BAKKESMOD_PLUGIN_IMPORT ReplayServerWrapper : public ServerWrapper
{
public:
	ReplayServerWrapper(std::uintptr_t server, std::uintptr_t gameinfo, std::uintptr_t replaydirector);
	ReplayServerWrapper(const ReplayServerWrapper& other);
	ReplayServerWrapper& operator=(ReplayServerWrapper rhs);
	~ReplayServerWrapper();
	ActorWrapper GetViewTarget();
	ReplayWrapper GetReplay();
	float GetReplayTimeElapsed();
	int32_t GetReplayFPS();
	int32_t GetCurrentReplayFrame();
	void AddKeyFrame(int32_t frame, std::string name);
	void RemoveKeyFrame(int32_t frame);
	void SkipToFrame(int32_t frame);
	void SkipToTime(float time);
	
	void StartPlaybackAtFrame(int32_t frame);
	void StartPlaybackAtTime(float time);
private:
	PIMPL
};