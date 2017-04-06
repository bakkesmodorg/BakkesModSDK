#pragma once
#include "actorwrapper.h"
#include "carwrapper.h"
#include "teamwrapper.h"
#include "priwrapper.h"
#include "ballwrapper.h"
template<typename T> 
class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper
{
public:
	ArrayWrapper(std::uintptr_t mem);
	ArrayWrapper(const ArrayWrapper& other);
	ArrayWrapper& operator=(ArrayWrapper rhs);
	~ArrayWrapper();

	int Count();
	T Get(int index);
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

//
template class ArrayWrapper<ActorWrapper>;
template class ArrayWrapper<TeamWrapper>;
template class ArrayWrapper<CarWrapper>;
//template class ArrayWrapper<TouchWrapper>;
template class ArrayWrapper<BallWrapper>;
template class ArrayWrapper<PriWrapper>;


#ifdef IS_PLUGIN:

#endif
