#pragma once
#include "actorwrapper.h"

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


class ActorWrapper;
class CarWrapper;
class BallWrapper;
class PriWrapper;
class WheelWrapper;
//
template class ArrayWrapper<ActorWrapper>;
//template class ArrayWrapper<TeamWrapper>;
template class ArrayWrapper<CarWrapper>;
//template class ArrayWrapper<TouchWrapper>;
template class ArrayWrapper<BallWrapper>;
template class ArrayWrapper<PriWrapper>;
template class ArrayWrapper<WheelWrapper>;