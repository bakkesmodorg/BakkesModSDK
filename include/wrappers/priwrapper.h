#pragma once
#include "carwrapper.h"
#include "boostwrapper.h"
#include "wrapperstructs.h"

class BAKKESMOD_PLUGIN_IMPORT PriWrapper : public ActorWrapper
{
public:
	CONSTRUCTORS(PriWrapper)

	//AUTO GENERATED
	GETSETH(int, Score)
	GETSETH(int, Goals)
	GETSETH(int, Assists)
	GETSETH(int, Saves)
	GETSETH(int, Shots)
	GETSETH(int, Demolishes)
	GETSETH(bool, UsingSecondaryCamera)
	GETSETH(bool, UsingFreeCamera)
	GETSETH(int, BallTouchCount)
	GETSETH(int, CarTouchCount)
	GETSETH(int, RespawnTimeRemaining)
	GETSETH(bool, Ready)
	GETSETH(float, ExactPing)
	GETSETH(bool, IsBot)
	GETSETH(int, PlayerID)
	CarWrapper GetCar();

	//SELF IMPLEMENTED
	int GetTeamIndex();
	string GetPlayerName();
	bool IsSpectator();
	int GetBody();
	//int GetTeamScore();
	//int GetTeamSize();
	//string GetTeamName();
private:
	PIMPL
};

