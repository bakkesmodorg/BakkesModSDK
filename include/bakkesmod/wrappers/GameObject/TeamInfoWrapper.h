#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT TeamInfoWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(TeamInfoWrapper)

	//AUTO-GENERATED FROM FIELDS
	UnrealStringWrapper GetTeamName();
	int GetSize();
	void SetSize(int newSize);
	int GetScore();
	void SetScore(int newScore);
	int GetTeamIndex();
	void SetTeamIndex(int newTeamIndex);
	UnrealColor GetTeamColor();
	void SetTeamColor(UnrealColor newTeamColor);

	//AUTO-GENERATED FUNCTION PROXIES
	unsigned char GetTeamNum();
	void eventDestroyed();
private:
	PIMPL
};