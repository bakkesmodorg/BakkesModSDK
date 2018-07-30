#pragma once
#include "./Engine/ActorWrapper.h"
#include "./GameObject/CarWrapper.h"
#include "./GameObject/BallWrapper.h"
#include "./GameObject/PriWrapper.h"
#include "./GameObject/CarComponent/WheelWrapper.h"
#include "./GameObject/RBActorWrapper.h"
#include "./GameObject/CarComponent/CarComponentWrapper.h"
#include "./GameObject/TeamWrapper.h"
#include "./GameObject/GoalWrapper.h"
#include "./GameObject/BoostPickupWrapper.h"
class ActorWrapper;
class CarWrapper;
class BallWrapper;

class WheelWrapper;
class RBActorWrapper;
class CarComponentWrapper;
class TeamWrapper;
class GoalWrapper;
class BoostPickupWrapper;


template<typename T> 
class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper
{
public:
	ArrayWrapper(std::uintptr_t mem);
	ArrayWrapper(const ArrayWrapper<T>& other);
	ArrayWrapper& operator=(ArrayWrapper<T> rhs);
	~ArrayWrapper();

	int Count();
	T Get(int index);
protected:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};



//
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ActorWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<TeamWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<CarWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<BallWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<PriWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<WheelWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<RBActorWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<CarComponentWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<GoalWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<BoostPickupWrapper>;
