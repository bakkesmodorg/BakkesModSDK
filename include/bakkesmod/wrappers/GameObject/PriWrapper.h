#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/PriXWrapper.h"
class UnrealStringWrapper;
class CarWrapper;
class GameEventWrapper;
class FXActorWrapper;
class AirControlComponentWrapper;
class ClubDetailsWrapper;
class UniqueIDWrapper;
class CameraSettingsActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT PriWrapper : public PriXWrapper {
public:
	CONSTRUCTORS(PriWrapper)

	//AUTO-GENERATED FROM FIELDS
	int GetMatchScore();
	void SetMatchScore(int newMatchScore);
	int GetMatchGoals();
	void SetMatchGoals(int newMatchGoals);
	int GetMatchOwnGoals();
	void SetMatchOwnGoals(int newMatchOwnGoals);
	int GetMatchAssists();
	void SetMatchAssists(int newMatchAssists);
	int GetMatchSaves();
	void SetMatchSaves(int newMatchSaves);
	int GetMatchShots();
	void SetMatchShots(int newMatchShots);
	int GetMatchDemolishes();
	void SetMatchDemolishes(int newMatchDemolishes);
	int GetMatchBonusXP();
	void SetMatchBonusXP(int newMatchBonusXP);
	int GetMatchBreakoutDamage();
	void SetMatchBreakoutDamage(int newMatchBreakoutDamage);
	unsigned long GetbMatchMVP();
	void SetbMatchMVP(unsigned long newbMatchMVP);
	unsigned long GetbMatchAdmin();
	void SetbMatchAdmin(unsigned long newbMatchAdmin);
	unsigned long GetbLoadoutSet();
	void SetbLoadoutSet(unsigned long newbLoadoutSet);
	unsigned long GetbOnlineLoadoutSet();
	void SetbOnlineLoadoutSet(unsigned long newbOnlineLoadoutSet);
	unsigned long GetbLoadoutsSet();
	void SetbLoadoutsSet(unsigned long newbLoadoutsSet);
	unsigned long GetbOnlineLoadoutsSet();
	void SetbOnlineLoadoutsSet(unsigned long newbOnlineLoadoutsSet);
	unsigned long GetbTeamPaintSet();
	void SetbTeamPaintSet(unsigned long newbTeamPaintSet);
	unsigned long GetbReady();
	void SetbReady(unsigned long newbReady);
	unsigned long GetbBusy();
	void SetbBusy(unsigned long newbBusy);
	unsigned long GetbUsingSecondaryCamera();
	void SetbUsingSecondaryCamera(unsigned long newbUsingSecondaryCamera);
	unsigned long GetbUsingBehindView();
	void SetbUsingBehindView(unsigned long newbUsingBehindView);
	unsigned long GetbUsingFreecam();
	void SetbUsingFreecam(unsigned long newbUsingFreecam);
	unsigned long GetbIsInSplitScreen();
	void SetbIsInSplitScreen(unsigned long newbIsInSplitScreen);
	unsigned long GetbStartVoteToForfeitDisabled();
	void SetbStartVoteToForfeitDisabled(unsigned long newbStartVoteToForfeitDisabled);
	unsigned long GetbUsingItems();
	void SetbUsingItems(unsigned long newbUsingItems);
	unsigned long GetPlayerHistoryValid();
	void SetPlayerHistoryValid(unsigned long newPlayerHistoryValid);
	GameEventWrapper GetGameEvent();
	void SetGameEvent(GameEventWrapper newGameEvent);
	GameEventWrapper GetReplicatedGameEvent();
	void SetReplicatedGameEvent(GameEventWrapper newReplicatedGameEvent);
	CarWrapper GetCar();
	void SetCar(CarWrapper newCar);
	int GetRespawnTimeRemaining();
	void SetRespawnTimeRemaining(int newRespawnTimeRemaining);
	int GetWaitingStartTime();
	void SetWaitingStartTime(int newWaitingStartTime);
	float GetTotalGameTimePlayed();
	void SetTotalGameTimePlayed(float newTotalGameTimePlayed);
	ProfileCameraSettings GetCameraSettings();
	void SetCameraSettings(ProfileCameraSettings newCameraSettings);
	unsigned char GetCameraPitch();
	void SetCameraPitch(unsigned char newCameraPitch);
	unsigned char GetCameraYaw();
	void SetCameraYaw(unsigned char newCameraYaw);
	unsigned char GetPawnType();
	void SetPawnType(unsigned char newPawnType);
	unsigned char GetReplicatedWorstNetQualityBeyondLatency();
	void SetReplicatedWorstNetQualityBeyondLatency(unsigned char newReplicatedWorstNetQualityBeyondLatency);
	CameraSettingsActorWrapper GetPersistentCamera() const;

	[[deprecated("Use GetPartyLeaderID instead")]]
	SteamID GetPartyLeader();//DEPRECATED
	[[deprecated("Use SetPartyLeader that takes UniqueIDWrapper instead")]]
	void SetPartyLeader(SteamID newPartyLeader);//DEPRECATED

	UniqueIDWrapper GetPartyLeaderID();
	void SetPartyLeader(UniqueIDWrapper newPartyLeader);

	float GetDodgeInputThreshold();
	void SetDodgeInputThreshold(float newDodgeInputThreshold);
	float GetSteeringSensitivity();
	void SetSteeringSensitivity(float newSteeringSensitivity);
	float GetAirControlSensitivity();
	void SetAirControlSensitivity(float newAirControlSensitivity);
	float GetNextTimeRestrictedStatEventAllowedTime();
	void SetNextTimeRestrictedStatEventAllowedTime(float newNextTimeRestrictedStatEventAllowedTime);
	float GetLastTimeRestrictedStatEventTime();
	void SetLastTimeRestrictedStatEventTime(float newLastTimeRestrictedStatEventTime);
	int GetTimeTillItem();
	void SetTimeTillItem(int newTimeTillItem);
	int GetMaxTimeTillItem();
	void SetMaxTimeTillItem(int newMaxTimeTillItem);
	int GetBoostPickups();
	void SetBoostPickups(int newBoostPickups);
	int GetBallTouches();
	void SetBallTouches(int newBallTouches);
	int GetCarTouches();
	void SetCarTouches(int newCarTouches);
	PriWrapper GetReplacingBotPRI();
	void SetReplacingBotPRI(PriWrapper newReplacingBotPRI);
	unsigned long long GetClubID();
	void SetClubID(unsigned long long newClubID);
	UnrealStringWrapper GetPublicIP();
	int GetSpectatorShortcut();
	void SetSpectatorShortcut(int newSpectatorShortcut);
	ClubDetailsWrapper GetClubDetails();

	//AUTO-GENERATED FUNCTION PROXIES
	void __ClubID__ChangeNotifyFunc();
	void __PREI__ChangeNotifyFunc();
	void __ReplicatedWorstNetQualityBeyondLatency__ChangeNotifyFunc();
	void eventDestroyed();
	void OnSpectatorShortcutChanged();
	void SetSpectatorShortcut2(int InShortcut);
	void ServerSetPublicIP(std::string IP);
	void OnUniqueIdChanged();
	void UpdatePlayerAvatarBorder();
	void UpdatePlayerBanner();
	void ClientAchievementProgression(int AchievementId, unsigned char AchievementType, float Progress, float MaxProgress);
	void ClientUnlockAchievement(int AchievementId, unsigned char AchievementType);
	void ServerSetPlayerActivatedFX(FXActorWrapper FX);
	void UpdateCarLocalPlayer();
	void OnReplacingBotPRIChanged();
	void OnTeamChanged();
	void ClearBotReplacement();
	void ReportCheater(std::string Reason);
	bool ValidateLoadoutTeamPaints();
	bool ValidateLoadoutSlots();
	void ValidateLoadoutDLC();
	void OnStartVoteToForfeitDisabledChanged();
	void SetStartVoteToForfeitDisabled(unsigned long bDisabled);
	void ServerVoteToForfeit();
	void SetUserCarPreferences(float NewDodgeThreshold, float NewSteeringSensitivity, float NewAirControlSensitivity);
	void ServerSetUserCarPreferences(float NewDodgeThreshold, float NewSteeringSensitivity, float NewAirControlSensitivity);
	int ValidateUserInt(std::string Reason, int NewValue, int Min, int Max);
	float ValidateUserFloat(std::string Reason, float NewValue, float Min, float Max);
	void OnPawnTypeChanged();
	void SetWaitingPlayer(unsigned long B);
	void SetPawnType2(unsigned char NewPawnType);
	bool IsPlayer();
	bool IsEditor();
	bool IsSpectator();
	void ServerSpectate();
	void ClientChangeTeamFailed(int TeamNum);
	void ServerChangeTeam(int TeamNum);
	void ReplicatePodiumTitles();
	void OnMatchAdmin();
	void OnMVPChange();
	void NotifyWonMVP();
	bool IsInvalidName();
	bool IsInWarmUpMode();
	void SetReady(unsigned long bNewReady);
	void ServerMatchAdminSetPaused(unsigned long bPause);
	void ServerMatchAdminSetScoreAndTime(int NewScoreTeam0, int NewScoreTeam1, int SecondsRemaining, unsigned long bOverTime, unsigned long bRestartRound);
	void SetMatchAdmin(unsigned long bIsMatchAdmin);
	void ServerReadyUp();
	bool ShouldBroadCastWelcomeMessage(unsigned long bExiting);
	void UpdateOnlineProductStats();
	void SetWaitingStartTime2();
	void OnRespawnTimeRemainingChanged();
	void SetRespawnTime2(int NewTime);
	void ClientScoredGoal(Vector& BallHitLocation);
	void OnScoredGoal(Vector& BallHitLocation);
	void OnRep_SteeringSensitivity();
	void OnRep_ClientScorePoint();
	void ResetScore();
	void RemovePoints(int Points);
	void ScorePoint2(int AdditionalScore);
	bool CanAwardTimeRestrictedStatEvent();
	void RecordTimeRestrictedStatEvent();
	void ResetTimeRestrictedStatEvent();
	int GetMatchXP();
	void CommitStats();
	void UpdateFromLoadout();
	void UpdateUserCarPreferences(AirControlComponentWrapper AirControlComponent);
	void HandleAirControl(AirControlComponentWrapper AirControlComp);
	void SetCar2(CarWrapper NewCar);
	bool IsClientPlayerPRI();
	bool IsLocalPlayerPRI();
	void Unregister();
	void AddLocalPlayerToGameEvent();
	void OnLoadoutsSetInternal();
	bool AreLoadoutsSet();
	void OnLoadoutsOnlineSet();
	void OnLoadoutsSet2();
	void RemoveCertifiedProductStat(unsigned long long InstanceID);
	void InitLoadoutAttributesForTeam(PriXWrapper PRI);
	bool ShouldValidateOnlineProducts();
	void OnSplitScreenStatusChanged();
	void ServerSplitScreenStatusChanged(unsigned long bInSplitScreen);
	void UpdateSplitScreenStatus();
	void OnPartyLeaderChanged();
	[[deprecated("Function definition is empty and thus will not work")]]
	void ServerSetPartyLeader(SteamID& InPartyLeader, unsigned long bInParty);//DEPRECATED
	[[deprecated("Function definition is empty and thus will not work")]]
	void SetPartyLeader2(SteamID& InPartyLeader, unsigned long bInParty);//DEPRECATED
	void UpdatePartyStatus();
	void OnSkillTierChanged();
	void ReplicateSkillTier(int NewTier);
	void OnTitleChanged();
	void SyncPlayerTitle();
	void UpdateTitleFromLoadout();
	void UpdateTitle2();
	void GetNewFriendKey();
	void ServerSetPlayerHistoryKey(unsigned char* HistoryKeyArray);
	void OnRep_UniqueId();
	void EventOwnerChanged(PriWrapper PRI);
	void EventSpectatorShortcutChanged(PriWrapper PRI);
	void EventServerAchievementProgression(PriWrapper PRI, int AchievementId, unsigned char AchievementType, float Progress, float MaxProgress);
	void EventStartVoteToForfeitDisabledChanged(PriWrapper PRI);
	void EventCarPreUpdate(PriWrapper PRI);
	void EventVanityChanged();
private:
	PIMPL
};