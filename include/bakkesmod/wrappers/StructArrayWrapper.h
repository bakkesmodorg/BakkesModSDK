#pragma once
#pragma warning(push)
#pragma warning(disable:4661)
#include "WrapperStructs.h"
#include "./Engine/ActorWrapper.h"
//struct RecordedSample;
//struct ProfileCameraSettings;
//struct SteamID;
//struct LinearColor;

struct ClubMember;
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
    PIMPL
};



//
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<RecordedSample>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<ProfileCameraSettings>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<SteamID>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<LinearColor>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<ClubMember>;
template class BAKKESMOD_PLUGIN_IMPORT StructArrayWrapper<TrainingRoundProgress>;
#pragma warning(pop)