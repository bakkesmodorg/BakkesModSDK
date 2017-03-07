#pragma once
#include "serverwrapper.h"
#include "carwrapper.h"
class BAKKESMOD_PLUGIN_IMPORT TutorialWrapper : public ServerWrapper
{
public:
	TutorialWrapper(std::uintptr_t mem);
	TutorialWrapper(const TutorialWrapper& other);
	TutorialWrapper& operator=(TutorialWrapper rhs);
	~TutorialWrapper();

	int GetTeamNum();
	int GetBallGoalNum(); //Can be both
	bool IsScoreAllowedBothGoals();
	void SetScoreAllowedBothGoals(bool b);

	void Redo();

	int GetRedoCount();
	void SetRedoCount(int redoCount);

	int GetRedoTotal();
	void SetRedoTotal(int redoTotal);

	float GetCountdownTime();
	void SetCountdownTime(float countdownTime);

	Vector GetBallSpawnLocation();
	void SetBallSpawnLocation(Vector v);

	Vector GetBallStartVelocity();
	void SetBallStartVelocity(Vector v);

	Vector GetCarSpawnLocation();
	void SetCarSpawnLocation(Vector v);

	Rotator GetCarSpawnRotation();
	void SetCarSpawnRotation(Rotator v);

	CarWrapper GetGameCar();

	bool IsUnlimitedBoost();
	void SetUnlimitedBoost(bool unlimitedBoost);

	bool IsBallMovingTowardsGoal(int goalNo);
	bool IsInGoal(Vector vec);

	void DisableGoalReset();
	void EnableGoalReset();
	
	void SpawnCar();

	//Speed from 0 to 2000 pls
	Vector GenerateShot(Vector startPos, Vector destination, float speed);
	Vector GenerateGoalAimLocation(int goalNumber, Vector currentBallLocation);
	Vector GetGoalExtent(int goalNumber = 0);

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};

