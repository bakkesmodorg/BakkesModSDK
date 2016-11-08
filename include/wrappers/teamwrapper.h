#pragma once
#include "actorwrapper.h"
#include "wrapperstructs.h"

#define TEAM_BLUE 0
#define TEAM_RED 1


class BAKKESMOD_PLUGIN_IMPORT TeamWrapper : public ActorWrapper
{
public:
	TeamWrapper(std::uintptr_t mem);
	TeamWrapper(const TeamWrapper& other);
	TeamWrapper& operator=(TeamWrapper rhs);
	~TeamWrapper();

	int GetScore();
	void SetScore(int score);

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};