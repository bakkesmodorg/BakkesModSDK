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
	int GetReplayFPS();
	int GetCurrentReplayFrame();
	void AddKeyFrame(int frame, string name);
	void RemoveKeyFrame(int frame);
	void SkipToFrame(int frame);
	void SkipToTime(float time);
	
	void StartPlaybackAtFrame(int frame);
	void StartPlaybackAtTime(float time);
private:
	PIMPL
};