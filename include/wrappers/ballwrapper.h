#pragma once
#include "wrapperstructs.h"
#include "actorwrapper.h"


class BAKKESMOD_PLUGIN_IMPORT BallWrapper : public ActorWrapper
{

public:
	CONSTRUCTORS(BallWrapper)

	//AUTO GENERATED
	GETSETH(int, GravityScale)
	GETSETH(float, ExplosionTime)

	//SELF IMPLEMENTED
	float GetLastTouchTime();
	bool IsExploded();
	void StopDoingShit();
	//ArrayWrapper<TouchWrapper> GetTouches();

private:
	PIMPL
};

