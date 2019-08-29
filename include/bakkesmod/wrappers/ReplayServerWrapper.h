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
	int GetReplayFPS();
	int GetCurrentReplayFrame();
	void AddKeyFrame(int frame, std::string name);
	void RemoveKeyFrame(int frame);
	void SkipToFrame(int frame);
	void SkipToTime(float time);
	
	void StartPlaybackAtFrame(int frame);
	void StartPlaybackAtTime(float time);
private:
	PIMPL
};