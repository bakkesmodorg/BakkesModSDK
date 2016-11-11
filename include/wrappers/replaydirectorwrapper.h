#pragma once
#include "actorwrapper.h"
#include "boostwrapper.h"
#include "wrapperstructs.h"
class BAKKESMOD_PLUGIN_IMPORT ReplayDirectorWrapper : public ActorWrapper
{
public:
	ReplayDirectorWrapper(std::uintptr_t mem);
	ReplayDirectorWrapper(const ReplayDirectorWrapper& other);
	ReplayDirectorWrapper& operator=(ReplayDirectorWrapper rhs);
	~ReplayDirectorWrapper();

	ActorWrapper GetViewTarget();

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};
