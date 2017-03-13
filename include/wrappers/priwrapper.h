#pragma once
#include "carwrapper.h"
#include "boostwrapper.h"
#include "wrapperstructs.h"

class BAKKESMOD_PLUGIN_IMPORT PriWrapper : public ActorWrapper
{
public:
	PriWrapper(std::uintptr_t mem);
	PriWrapper(const PriWrapper& other);
	PriWrapper& operator=(PriWrapper rhs);
	~PriWrapper();

	int GetScore();
	int GetGoals();
	int GetAssists();
	int GetSaves();
	int GetShots();
	int GetDemolishes();
	bool IsUsingSecondaryCamera();
	bool IsUsingFreeCamera();
	int GetBallTouchCount();
	int GetCarTouchCount();
	int GetRespawnTimeRemaining();
	bool IsReady();
	bool IsSpectator();
	float GetPing();
	bool IsBot();
	int GetPlayerID();
	int GetTeamIndex();
	string GetPlayerName();
	CarWrapper GetCar();
	//int GetTeamScore();
	//int GetTeamSize();
	//string GetTeamName();
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

