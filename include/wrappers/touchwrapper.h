#include "stdafx.h"
#pragma once
class BAKKESMOD_PLUGIN_IMPORT TouchWrapper
{

public:
	TouchWrapper(std::uintptr_t mem);
	TouchWrapper(const TouchWrapper& other);
	TouchWrapper& operator=(TouchWrapper rhs);
	~TouchWrapper();


private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};
