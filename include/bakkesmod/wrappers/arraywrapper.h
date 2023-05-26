#pragma once
#pragma warning(push)
#pragma warning(disable:4661)
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
#include "GameObject/BreakOutActorPlatformWrapper.h"

class ProductPaintWrapper;
class MapDataWrapper;
class ProductSlotWrapper;
class LoadingProductWrapper;
class LoadoutSetWrapper;
class ActorWrapper;
class CarWrapper;
class BallWrapper;

class WheelWrapper;
class RBActorWrapper;
class CarComponentWrapper;
class TeamWrapper;
class GoalWrapper;
class BoostPickupWrapper;
class SampleHistoryWrapper;
class StatGraphWrapper;
class ControllerWrapper;
class PlayerControllerWrapper;

class SequenceWrapper;
class SequenceObjectWrapper;
class SequenceVariableWrapper;

class ProductWrapper;
class OnlineProductWrapper;
class ProductAttributeWrapper;

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
    bool IsNull();
protected:
	PIMPL
};

template <typename T>
class ArrayWrapperIterator
{
public:
    ArrayWrapperIterator(ArrayWrapper<T>& collection,
        size_t const index) :
        index(index), collection(collection)
    { }

    bool operator!= (ArrayWrapperIterator const& other) const
    {
        return index != other.index;
    }

    T operator* () const
    {
        return collection.Get(index);
    }

    ArrayWrapperIterator const& operator++ ()
    {
        ++index;
        return *this;
    }

private:
    size_t   index;
    ArrayWrapper<T>& collection;
};

template <typename T>
inline ArrayWrapperIterator<T> begin(
    ArrayWrapper<T>& collection)
{
    return ArrayWrapperIterator<T>(collection, 0);
}

template <typename T>
inline ArrayWrapperIterator<T> end(
    ArrayWrapper<T>& collection)
{
    return ArrayWrapperIterator<T>(
        collection, collection.Count());
}


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
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<SampleHistoryWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<StatGraphWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ControllerWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<PlayerControllerWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<wchar_t>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<SequenceWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<SequenceObjectWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<SequenceVariableWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ProductWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<OnlineProductWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ProductAttributeWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<int>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<unsigned long long>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<BreakOutActorPlatformWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<LoadoutSetWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<LoadingProductWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ProductSlotWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<MapDataWrapper>;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<ProductPaintWrapper>;
//template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<FSample>;
#pragma warning(pop)