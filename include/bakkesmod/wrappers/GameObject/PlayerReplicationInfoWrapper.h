#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"
class UnrealStringWrapper;

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
	UnrealStringWrapper GetPlayerName();
	UnrealStringWrapper GetOldName();
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
	UnrealStringWrapper GetStringSpectating();
	UnrealStringWrapper GetStringUnknown();
	int GetKills();
	void SetKills(int newKills);
	float GetExactPing();
	void SetExactPing(float newExactPing);
	UnrealStringWrapper GetSavedNetworkAddress();
	SteamID GetUniqueId();
	void SetUniqueId(SteamID newUniqueId);

	//AUTO-GENERATED FUNCTION PROXIES
	bool IsPrimaryPlayer();
	void UnregisterPlayerFromSession();
	void RegisterPlayerWithSession();
	bool IsInvalidName();
	unsigned char GetTeamNum();
	void SetUniqueId2(SteamID& PlayerUniqueId);
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