#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT PlayerReplicationInfoWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(PlayerReplicationInfoWrapper)

	//BEGIN SELF IMPLEMENTED
	unsigned long long GetSteamID();	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	int GetScore();
	void SetScore(int newScore);
	int GetDeaths();
	void SetDeaths(int newDeaths);
	unsigned char GetPing();
	void SetPing(unsigned char newPing);
	unsigned char GetTTSSpeaker();
	void SetTTSSpeaker(unsigned char newTTSSpeaker);
	int GetNumLives();
	void SetNumLives(int newNumLives);
	int GetPlayerID();
	void SetPlayerID(int newPlayerID);
	unsigned long GetbAdmin();
	void SetbAdmin(unsigned long newbAdmin);
	unsigned long GetbIsSpectator();
	void SetbIsSpectator(unsigned long newbIsSpectator);
	unsigned long GetbOnlySpectator();
	void SetbOnlySpectator(unsigned long newbOnlySpectator);
	unsigned long GetbWaitingPlayer();
	void SetbWaitingPlayer(unsigned long newbWaitingPlayer);
	unsigned long GetbReadyToPlay();
	void SetbReadyToPlay(unsigned long newbReadyToPlay);
	unsigned long GetbOutOfLives();
	void SetbOutOfLives(unsigned long newbOutOfLives);
	unsigned long GetbBot();
	void SetbBot(unsigned long newbBot);
	unsigned long GetbHasBeenWelcomed();
	void SetbHasBeenWelcomed(unsigned long newbHasBeenWelcomed);
	unsigned long GetbIsInactive();
	void SetbIsInactive(unsigned long newbIsInactive);
	unsigned long GetbFromPreviousLevel();
	void SetbFromPreviousLevel(unsigned long newbFromPreviousLevel);
	unsigned long GetbTimedOut();
	void SetbTimedOut(unsigned long newbTimedOut);
	unsigned long GetbUnregistered();
	void SetbUnregistered(unsigned long newbUnregistered);
	int GetStartTime();
	void SetStartTime(int newStartTime);
	int GetKills();
	void SetKills(int newKills);
	float GetExactPing();
	void SetExactPing(float newExactPing);
	int GetStatConnectionCounts();
	void SetStatConnectionCounts(int newStatConnectionCounts);
	int GetStatPingTotals();
	void SetStatPingTotals(int newStatPingTotals);
	int GetStatPingMin();
	void SetStatPingMin(int newStatPingMin);
	int GetStatPingMax();
	void SetStatPingMax(int newStatPingMax);
	int GetStatPKLTotal();
	void SetStatPKLTotal(int newStatPKLTotal);
	int GetStatPKLMin();
	void SetStatPKLMin(int newStatPKLMin);
	int GetStatPKLMax();
	void SetStatPKLMax(int newStatPKLMax);
	int GetStatMaxInBPS();
	void SetStatMaxInBPS(int newStatMaxInBPS);
	int GetStatAvgInBPS();
	void SetStatAvgInBPS(int newStatAvgInBPS);
	int GetStatMaxOutBPS();
	void SetStatMaxOutBPS(int newStatMaxOutBPS);
	int GetStatAvgOutBPS();
	void SetStatAvgOutBPS(int newStatAvgOutBPS);

	//AUTO-GENERATED FUNCTION PROXIES
	bool IsPrimaryPlayer();
	void UnregisterPlayerFromSession();
	void RegisterPlayerWithSession();
	bool IsInvalidName();
	unsigned char GetTeamNum();
	void SeamlessTravelTo(PlayerReplicationInfoWrapper NewPRI);
	void IncrementDeaths(int Amt);
	void CopyProperties(PlayerReplicationInfoWrapper PRI);
	void OverrideWith(PlayerReplicationInfoWrapper PRI);
	PlayerReplicationInfoWrapper Duplicate();
	void SetWaitingPlayer(unsigned long B);
	void Reset();
	void eventDestroyed();
	void Unregister2();
	bool ShouldBroadCastWelcomeMessage(unsigned long bExiting);
	void UpdatePing(float TimeStamp);
	void RemoteUserDataReplicated();
	void eventClientFillRemoteUserData();
	void eventPostBeginPlay();
private:
	PIMPL
};