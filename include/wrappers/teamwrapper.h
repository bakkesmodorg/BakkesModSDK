#pragma once
#include "actorwrapper.h"
#include "wrapperstructs.h"
#include "arraywrapper.h"
#define TEAM_BLUE 0
#define TEAM_RED 1

class BAKKESMOD_PLUGIN_IMPORT TeamWrapper : public ActorWrapper
{
public:
	CONSTRUCTORS(TeamWrapper)

	//AUTO GENERATED
	GETSETH(int, Score)
	int GetTeamSize();
	int GetIndex();
	//string GetTeamName();

	//CUSTOM IMPLEMENTED
	//ArrayWrapper<PriWrapper> GetMembers();
	int GetBotCount();
	int GetHumanCount();
	

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};