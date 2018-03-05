#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"
class CarWrapper;
class PriWrapper;

class BAKKESMOD_PLUGIN_IMPORT GameEventWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(GameEventWrapper)

	//AUTO-GENERATED FROM FIELDS
	unsigned char GetGameMode();
	void SetGameMode(unsigned char newGameMode);
	unsigned char GetReplicatedStateIndex();
	void SetReplicatedStateIndex(unsigned char newReplicatedStateIndex);
	CarWrapper GetCarArchetype();
	void SetCarArchetype(CarWrapper newCarArchetype);
	int GetCountdownTime();
	void SetCountdownTime(int newCountdownTime);
	int GetFinishTime();
	void SetFinishTime(int newFinishTime);
	unsigned long GetbMultiplayer();
	void SetbMultiplayer(unsigned long newbMultiplayer);
	unsigned long GetbFillWithAI();
	void SetbFillWithAI(unsigned long newbFillWithAI);
	unsigned long GetbAllowReadyUp();
	void SetbAllowReadyUp(unsigned long newbAllowReadyUp);
	unsigned long GetbRestartingMatch();
	void SetbRestartingMatch(unsigned long newbRestartingMatch);
	unsigned long GetbRandomizedBotLoadouts();
	void SetbRandomizedBotLoadouts(unsigned long newbRandomizedBotLoadouts);
	unsigned long GetbHasLeaveMatchPenalty();
	void SetbHasLeaveMatchPenalty(unsigned long newbHasLeaveMatchPenalty);
	unsigned long GetbCanVoteToForfeit();
	void SetbCanVoteToForfeit(unsigned long newbCanVoteToForfeit);
	unsigned long GetbDisableAimAssist();
	void SetbDisableAimAssist(unsigned long newbDisableAimAssist);
	int GetMinPlayers();
	void SetMinPlayers(int newMinPlayers);
	int GetMaxPlayers();
	void SetMaxPlayers(int newMaxPlayers);
	ArrayWrapper<ActorWrapper> GetSpawnPoints();
	float GetBotSkill();
	void SetBotSkill(float newBotSkill);
	int GetRespawnTime();
	void SetRespawnTime(int newRespawnTime);
	float GetMatchTimeDilation();
	void SetMatchTimeDilation(float newMatchTimeDilation);
	CarWrapper GetActivatorCar();
	void SetActivatorCar(CarWrapper newActivatorCar);
	ArrayWrapper<PriWrapper> GetPRIs();
	ArrayWrapper<CarWrapper> GetCars();
	int GetStartPointIndex();
	void SetStartPointIndex(int newStartPointIndex);
	int GetGameStateTimeRemaining();
	void SetGameStateTimeRemaining(int newGameStateTimeRemaining);
	int GetReplicatedGameStateTimeRemaining();
	void SetReplicatedGameStateTimeRemaining(int newReplicatedGameStateTimeRemaining);
	float GetIdleKickTime();
	void SetIdleKickTime(float newIdleKickTime);
	float GetIdleKickWarningTime();
	void SetIdleKickWarningTime(float newIdleKickWarningTime);
	PriWrapper GetGameOwner();
	void SetGameOwner(PriWrapper newGameOwner);

	//AUTO-GENERATED FUNCTION PROXIES
	bool SuppressModalDialogs();
	bool ShouldShowBallIndicator();
	void CheckForBannedPlayers();
	bool AllowSplitScreenPlayer();
	void ConditionalStartSpectatorMatch();
	bool IsPlayingLan();
	bool IsPlayingOffline();
	bool IsPlayingPrivate();
	bool IsPlayingPublic();
	bool IsOnlineMultiplayer();
	bool AllPlayersSelectedTeam();
	bool CanQueSaveReplay();
	void ForceMatchStart();
	void ConditionalStartMatch();
	void SaveLocalPlayerStats();
	bool CanUseBallCam();
	bool HandleNextGame();
	void SetMaxPlayers2(int InMaxPlayers);
	void SetRestartingMatch(unsigned long bRestart);
	bool ShouldBeFullScreen();
	bool IsFinished();
	void OnAllPlayersReady();
	void CheckPlayersReady();
	void SetAllowReadyUp(unsigned long bAllow, unsigned long bReadySpectators);
	void KickSplitscreenIdlers();
	void KickIdlers();
	void StopIdleKickTimer();
	void StartIdleKickTimer(float OffsetTime);
	void BroadcastCountdownMessage(int Seconds);
	void BroadcastGoMessage();
	bool AllowShutdown();
	bool AllowScoreboard();
	float GetRealDeltaTime(float ElapsedTime);
	void SetTimeDilation(float NewTimeDilation);
	void ClearRespawnList();
	int GetRespawnTime2();
	void RemoveCar(CarWrapper Car);
	void AddCar(CarWrapper Car);
	void TickRespawnTime(float DeltaTime);
	void SetBotSkill2(float NewSkill);
	bool MoveToGround(ActorWrapper Mover, float HeightCheck);
	void SetAllDriving(unsigned long bDriving);
	void OnFinished();
	void StartCountDown();
	void StartInitialCountDown();
	void OnGameStateTimeLapsed();
	void OnGameStateTimeUpdated();
	void UpdateGameStateTime();
	void SetGameStateTimeRemaining2(int StateTime, unsigned long bFromReplication);
	void SetGameStateTime2(int StateTime);
	void OnPlayerRestarted(CarWrapper PlayerCar);
	void TeleportCar(CarWrapper PlayerCar);
	void OnCarSpawned(CarWrapper NewCar);
	bool SpotIsEncroached(Vector& Spot);
	void RandomizeSpawnPoints();
	void RestartPlayers();
	void RemovePRI(PriWrapper PRI);
	void AddPRI(PriWrapper PRI);
	int GetMaxHumans();
	int GetNumHumans();
	bool FindBotReplacement(PriWrapper PRI);
	void UpdateBotCount();
	void TimerUpdateBotCount();
	void InitBotSkill();
	void InitMutators();
	void HandleFinished(GameEventWrapper GameEvent);
	void OnGameStateChanged();
	void OnCanVoteForfeitChanged();
	void UpdateCanVoteToForfeit();
	bool ShouldAllowVoteToForfeit();
	void OnPenaltyChanged();
	void UpdateLeaveMatchPenalty();
	bool ShouldHaveLeaveMatchPenalty();
	void OnMatchSettingsChanged();
private:
	PIMPL
};