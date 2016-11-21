#pragma once
#include "gameeventwrapper.h"
#include "teamwrapper.h"
#include "arraywrapper.h"
#include "carwrapper.h"
class BAKKESMOD_PLUGIN_IMPORT ServerWrapper : public GameEventWrapper
{
public:
	ServerWrapper(std::uintptr_t mem);
	ServerWrapper(const ServerWrapper& other);
	ServerWrapper& operator=(ServerWrapper rhs);
	~ServerWrapper();

	int GetTimeRemaining();
	void SetTimeRemaining(int timeRemaining);
	TeamWrapper GetTeam(int teamNum);
	ArrayWrapper<TeamWrapper> GetTeams();
	ArrayWrapper<CarWrapper> GetPlayers();
	Vector GetGoalLocation(int goalNumber = 0);
	void SetPodiumTime(int podiumTime);

	float GetGameSpeed();
	void SetGameSpeed(float newSpeed);

	float GetSecondsElapsed();


	BallWrapper SpawnBall(Vector position, bool wake, bool spawnCannon=false);
	ArrayWrapper<BallWrapper> GetBalls();
	bool RemoveBall(BallWrapper ball);
	void MoveToGround(ActorWrapper ac, float heightCheck = 4096.0f);
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};