#pragma once
#include "serverwrapper.h"

class BAKKESMOD_PLUGIN_IMPORT ReplayWrapper : public ServerWrapper
{
public:
	ReplayWrapper(std::uintptr_t server, std::uintptr_t gameinfo, std::uintptr_t replaydirector);
	ReplayWrapper(const ReplayWrapper& other);
	ReplayWrapper& operator=(ReplayWrapper rhs);
	~ReplayWrapper();


	ActorWrapper GetViewTarget();
	float GetReplayTimeElapsed();

	int GetCurrentReplayFrame();
	void AddKeyFrame(int frame, string name);
	void RemoveKeyFrame(int frame);
	void SkipToTime(float time);
private:
	PIMPL
};