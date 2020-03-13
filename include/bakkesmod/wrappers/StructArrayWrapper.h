#pragma once
#pragma warning(push)
#pragma warning(disable:4661)
#include "bakkesmod/wrappers/WrapperStructs.h"
#include "./Engine/ActorWrapper.h"
//struct RecordedSample;
//struct ProfileCameraSettings;
//struct SteamID;
//struct LinearColor;
template<typename T>
class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper
{
public:
	StructArrayWrapper(std::uintptr_t mem);
	StructArrayWrapper(const StructArrayWrapper<T>& other);
	StructArrayWrapper& operator=(StructArrayWrapper<T> rhs);
	~StructArrayWrapper();

	int Count();
	T Get(int index);
protected:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};



//
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<RecordedSample>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<ProfileCameraSettings>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<SteamID>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<LinearColor>;
#pragma warning(pop)