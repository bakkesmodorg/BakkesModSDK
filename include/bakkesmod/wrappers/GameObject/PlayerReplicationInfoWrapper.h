#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include "../UniqueIDWrapper.h"
#include ".././Engine/ActorWrapper.h"
class UnrealStringWrapper;
class TeamInfoWrapper;

class BAKKESMOD_PLUGIN_IMPORT PlayerReplicationInfoWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(PlayerReplicationInfoWrapper)

	//BEGIN SELF IMPLEMENTED
	OnlinePlatform GetPlatform();
	_NODISCARD bool ChangeNameForScoreboardAndNameplateInReplay(const std::string& name); //sorry for long name..
	//END SELF IMPLEMENTED

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
	TeamInfoWrapper GetTeam();
	void SetTeam(TeamInfoWrapper newTeam);
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
	[[deprecated("Use GetUniqueIdWrapper instead")]]
	SteamID GetUniqueId();//DEPRECATED
	[[deprecated("Use SetUniqueId that takes UniqueIDWrapper instead")]]
	void SetUniqueId(SteamID newUniqueId);//DEPRECATED

	UniqueIDWrapper GetUniqueIdWrapper();
	void SetUniqueId(UniqueIDWrapper newUniqueId);

	//AUTO-GENERATED FUNCTION PROXIES
	void UnregisterPlayerFromSession();
	void RegisterPlayerWithSession();
	bool IsInvalidName();
	unsigned char GetTeamNum();
	[[deprecated("Use SetUniqueId2 that takes UniqueIDWrapper instead")]]
	void SetUniqueId2(SteamID& PlayerUniqueId);//DEPRECATED
	void SetUniqueId2(UniqueIDWrapper& PlayerUniqueId);
	void SeamlessTravelTo(PlayerReplicationInfoWrapper NewPRI);
	void IncrementDeaths(int Amt);
	void CopyProperties(PlayerReplicationInfoWrapper PRI);
	void OverrideWith(PlayerReplicationInfoWrapper PRI);
	PlayerReplicationInfoWrapper Duplicate();
	void SetWaitingPlayer(unsigned long B);
	void eventSetPlayerName(std::string S);
	void Reset();
	void eventDestroyed();
	void Unregister2();
	void UpdatePing(float TimeStamp);
	void RemoteUserDataReplicated();
	void SetPlayerTeam(TeamInfoWrapper NewTeam);
	void eventClientFillRemoteUserData();
	void eventPostBeginPlay();
	void eventOnOwnerChanged();
	void eventConstruct();
private:
	PIMPL
};