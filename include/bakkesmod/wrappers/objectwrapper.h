#pragma once
#include "bakkesmod/plugin/bakkesmodsdk.h"
#include "wrapperstructs.h"
#include <functional>
#include <memory>
#include <string>
using namespace std;

class BAKKESMOD_PLUGIN_IMPORT ObjectWrapper
{
public:
	std::uintptr_t memory_address;
	ObjectWrapper(std::uintptr_t mem);
};