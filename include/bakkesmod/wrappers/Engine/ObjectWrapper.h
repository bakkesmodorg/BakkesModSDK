#pragma once
#include "bakkesmod/plugin/bakkesmodsdk.h"
#include "../WrapperStructs.h"
#include <functional>
#include <memory>
#include <string>

class BAKKESMOD_PLUGIN_IMPORT ObjectWrapper
{
public:
	std::uintptr_t memory_address;
	ObjectWrapper(std::uintptr_t mem);
};