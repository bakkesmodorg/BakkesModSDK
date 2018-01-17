#pragma once
#include "serverwrapper.h"

class CarWrapper;

class BAKKESMOD_PLUGIN_IMPORT TutorialWrapper : public ServerWrapper
{
public:
	CONSTRUCTORS(TutorialWrapper)

	//AUTO GENERATED
	GETSETH(int, TeamNum)
	GETSETH(int, RedoCount)
	GETSETH(int, RedoTotal)
	GETSETH(float, CountdownTimeLeft)
	GETSETH(int, BallGoalNum)
	GETSETH(bool, OnlyScoreInBallGoalNum)
	GETSETH(bool, IsUnlimitedBoost)
	GETSETH(bool, ShowBoostMeter)
	GETSETH(float, BallBounceScale)
	GETSETH(Vector, BallSpawnLocation)
	GETSETH(Vector, BallStartVelocity)
	GETSETH(Vector, TotalFieldExtent)

	//SELF IMPLEMENTED
	void Redo();
	Vector GetCarSpawnLocation();
	void SetCarSpawnLocation(Vector v);
	Rotator GetCarSpawnRotation();
	void SetCarSpawnRotation(Rotator v);
	CarWrapper GetGameCar();

	bool IsBallMovingTowardsGoal(int goalNo, BallWrapper bw);
	bool IsInGoal(Vector vec);

	void DisableGoalReset();
	void EnableGoalReset();

	//void SpawnCar(int body = 0);

	//Speed from 0 to 2000 pls
	Vector GenerateShot(Vector startPos, Vector destination, float speed);
	Vector GenerateGoalAimLocation(int goalNumber, Vector currentBallLocation);
	Vector GetGoalExtent(int goalNumber = 0);


	//void SpawnCar2();
private:
	PIMPL
};

