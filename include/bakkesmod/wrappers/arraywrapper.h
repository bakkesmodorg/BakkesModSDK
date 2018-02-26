#pragma once
#include "./Engine/ActorWrapper.h"
#include "./GameObject/CarWrapper.h"
#include "./GameObject/BallWrapper.h"
#include "./GameObject/PriWrapper.h"
#include "./GameObject/CarComponent/WheelWrapper.h"
#include "./GameObject/RBActorWrapper.h"
#include "./GameObject/CarComponent/CarComponentWrapper.h"
#include "./GameObject/TeamWrapper.h"
class ActorWrapper;
class CarWrapper;
class BallWrapper;
class PriWrapper;
class WheelWrapper;
class RBActorWrapper;
class CarComponentWrapper;
class TeamWrapper;

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
template class ArrayWrapper<BallWrapper>;
template class ArrayWrapper<PriWrapper>;
template class ArrayWrapper<WheelWrapper>;
template class ArrayWrapper<RBActorWrapper>;
template class ArrayWrapper<CarComponentWrapper>;