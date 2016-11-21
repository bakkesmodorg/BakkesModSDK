#pragma once
#include "actorwrapper.h"
#include "carwrapper.h"
#include "teamwrapper.h"
#include "ballwrapper.h"
//#include "touchwrapper.h"
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
template class ArrayWrapper<TeamWrapper>;
template class ArrayWrapper<CarWrapper>;
template class ArrayWrapper<BallWrapper>;
#ifdef IS_PLUGIN:

//template class ArrayWrapper<TouchWrapper>;
#endif
