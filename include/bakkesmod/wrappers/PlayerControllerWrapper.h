#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "WrapperStructs.h"
#include "./Engine/ActorWrapper.h"
//#include "ControllerWrapper.h"
class BoostWrapper;
class UnrealStringWrapper;
class CarWrapper;
class PriXWrapper;
class GameEventWrapper;
class ServerWrapper;
class BaseCameraWrapper;
class RBActorWrapper;
class PriWrapper;
class EngineTAWrapper;
class PlayerReplicationInfoWrapper;

class BAKKESMOD_PLUGIN_IMPORT PlayerControllerWrapper : public ActorWrapper /*ControllerWrapper*/ {
public:
	CONSTRUCTORS(PlayerControllerWrapper)

	//AUTO-GENERATED FROM FIELDS
	CarWrapper GetCar();
	void SetCar(CarWrapper newCar);
	PriWrapper GetPRI();
	void SetPRI(PriWrapper newPRI);
	ControllerInput GetVehicleInput();
	void SetVehicleInput(ControllerInput newVehicleInput);
	unsigned long GetbReceivedServerShutdownMessage();
	void SetbReceivedServerShutdownMessage(unsigned long newbReceivedServerShutdownMessage);
	unsigned long GetbUseDebugInputs();
	void SetbUseDebugInputs(unsigned long newbUseDebugInputs);
	unsigned long GetbJumpPressed();
	void SetbJumpPressed(unsigned long newbJumpPressed);
	unsigned long GetbBoostPressed();
	void SetbBoostPressed(unsigned long newbBoostPressed);
	unsigned long GetbHandbrakePressed();
	void SetbHandbrakePressed(unsigned long newbHandbrakePressed);
	unsigned long GetbHasPitchedBack();
	void SetbHasPitchedBack(unsigned long newbHasPitchedBack);
	unsigned long GetbAllowAsymmetricalMute();
	void SetbAllowAsymmetricalMute(unsigned long newbAllowAsymmetricalMute);
	unsigned long GetbResetCamera();
	void SetbResetCamera(unsigned long newbResetCamera);
	UnrealStringWrapper GetLoginURL();
	uint8_t GetVoiceFilter();
	void SetVoiceFilter(uint8_t newVoiceFilter);
	uint8_t GetChatFilter();
	void SetChatFilter(uint8_t newChatFilter);
	PriWrapper GetFollowTarget();
	void SetFollowTarget(PriWrapper newFollowTarget);
	BaseCameraWrapper GetSpectatorCameraArchetype();
	void SetSpectatorCameraArchetype(BaseCameraWrapper newSpectatorCameraArchetype);
	BaseCameraWrapper GetEditorCameraArchetype();
	void SetEditorCameraArchetype(BaseCameraWrapper newEditorCameraArchetype);
	Vector GetMoveActorGrabOffset();
	void SetMoveActorGrabOffset(Vector newMoveActorGrabOffset);
	float GetMoveActorGrabIncrement();
	void SetMoveActorGrabIncrement(float newMoveActorGrabIncrement);
	float GetMinMoveActorGrabDistance();
	void SetMinMoveActorGrabDistance(float newMinMoveActorGrabDistance);
	float GetMouseIncrementSpeed();
	void SetMouseIncrementSpeed(float newMouseIncrementSpeed);
	float GetBallVelocityIncrementAmount();
	void SetBallVelocityIncrementAmount(float newBallVelocityIncrementAmount);
	int32_t GetBallVelocityIncrementFireCount();
	void SetBallVelocityIncrementFireCount(int32_t newBallVelocityIncrementFireCount);
	float GetBallVelocityIncrementFireCountMax();
	void SetBallVelocityIncrementFireCountMax(float newBallVelocityIncrementFireCountMax);
	float GetBallVelocityIncrementSpeedDefault();
	void SetBallVelocityIncrementSpeedDefault(float newBallVelocityIncrementSpeedDefault);
	float GetBallVelocityIncrementSpeedMax();
	void SetBallVelocityIncrementSpeedMax(float newBallVelocityIncrementSpeedMax);
	float GetCrosshairTraceDistance();
	void SetCrosshairTraceDistance(float newCrosshairTraceDistance);
	ActorWrapper GetTracedCrosshairActor();
	void SetTracedCrosshairActor(ActorWrapper newTracedCrosshairActor);
	Vector GetRotateActorCameraLocationOffset();
	void SetRotateActorCameraLocationOffset(Vector newRotateActorCameraLocationOffset);
	Vector GetRotateActorCameraRotationOffset();
	void SetRotateActorCameraRotationOffset(Vector newRotateActorCameraRotationOffset);
	int32_t GetRotateActorCameraSide();
	void SetRotateActorCameraSide(int32_t newRotateActorCameraSide);
	float GetDesiredCameraSide();
	void SetDesiredCameraSide(float newDesiredCameraSide);
	float GetPawnTypeChangedTime();
	void SetPawnTypeChangedTime(float newPawnTypeChangedTime);
	int32_t GetSelectedSpawnArchetype();
	void SetSelectedSpawnArchetype(int32_t newSelectedSpawnArchetype);
	ControllerInput GetDebugInputs();
	void SetDebugInputs(ControllerInput newDebugInputs);
	int32_t GetMinClientInputRate();
	void SetMinClientInputRate(int32_t newMinClientInputRate);
	int32_t GetMedianClientInputRate();
	void SetMedianClientInputRate(int32_t newMedianClientInputRate);
	int32_t GetMaxClientInputRate();
	void SetMaxClientInputRate(int32_t newMaxClientInputRate);
	int32_t GetConfiguredClientInputRate();
	void SetConfiguredClientInputRate(int32_t newConfiguredClientInputRate);
	float GetTimeSinceLastMovePacket();
	void SetTimeSinceLastMovePacket(float newTimeSinceLastMovePacket);
	float GetTimeLastReplicatedMovePacket();
	void SetTimeLastReplicatedMovePacket(float newTimeLastReplicatedMovePacket);
	float GetMouseXDeadZone();
	void SetMouseXDeadZone(float newMouseXDeadZone);
	float GetMouseYDeadZone();
	void SetMouseYDeadZone(float newMouseYDeadZone);
	float GetMouseXDeadZoneAir();
	void SetMouseXDeadZoneAir(float newMouseXDeadZoneAir);
	float GetMouseYDeadZoneAir();
	void SetMouseYDeadZoneAir(float newMouseYDeadZoneAir);
	ControllerInput GetLastInputs();
	void SetLastInputs(ControllerInput newLastInputs);
	PriWrapper GetPendingViewPRI();
	void SetPendingViewPRI(PriWrapper newPendingViewPRI);
	float GetLastInputPitchUp();
	void SetLastInputPitchUp(float newLastInputPitchUp);
	float GetLastInputPitchDown();
	void SetLastInputPitchDown(float newLastInputPitchDown);
	float GetLastInputYawLeft();
	void SetLastInputYawLeft(float newLastInputYawLeft);
	float GetLastInputYawRight();
	void SetLastInputYawRight(float newLastInputYawRight);
	float GetLastInputPitch();
	void SetLastInputPitch(float newLastInputPitch);
	float GetLastInputYaw();
	void SetLastInputYaw(float newLastInputYaw);
	float GetMouseInputMax();
	void SetMouseInputMax(float newMouseInputMax);
	EngineTAWrapper GetEngineShare();
	void SetEngineShare(EngineTAWrapper newEngineShare);

	//AUTO-GENERATED FUNCTION PROXIES
	void HandleCarSet(PriWrapper InPRI);
	void SpawnSelectedArchetype();
	bool RemoveActor();
	void ToggleGrabActor();
	void ToggleRotateActor();
	void EditorReleaseActor();
	void EditorCycleActor();
	void DuplicateShot();
	void StopEditing();
	void EditorIncreasePower();
	void EditorDecreasePower();
	void EditorIncreasePowerToggleInterim();
	void EditorDecreasePowerToggleInterim();
	void EditorIncreasePowerToggle2(unsigned long bToggle);
	void EditorDecreasePowerToggle2(unsigned long bToggle);
	void ModifyEditorPower(int32_t Direction);
	void ToggleCameraPosition();
	void EditorUndo();
	void EditorRedo();
	void EditorIncreaseRoundTime();
	void EditorDecreaseRoundTime();
	void EditorNextRound();
	void EditorPrevRound();
	void UpdateCrosshair();
	void NetClientInputRate(int32_t Rate);
	void ServerCreateMatchBroadcast(ServerWrapper GameEvent);
	void ClampMoveActorGrabOffset();
	void RevertToDefaultCameraHUDInput();
	void SwitchToEditPawn();
	void ServerResetPlayer(unsigned long bFullReset);
	void ResetPlayerRun();
	void ResetPlayerCheckpoint();
	void ToggleEditorRound();
	void ToggleBetweenCarAndEditPawn();
	void Interact();
	void StopMovement(unsigned long bOnlyIfNoAccel);
	Vector GetRotateActorCameraOffset(float DeltaTime, unsigned long bSnap);
	void RestoreEditorPawnOrientation();
	void BackupEditorPawnOrientation();
	void UpdateRotatedActorOrientation(float DeltaTime);
	void OnOpenPauseMenu();
	void ResetMouseCenter();
	float CalculateMouseAxis(float Center, float CurrentLocation, float Deadzone, float MaxDist);
	void ShowControllerApplet();
	void ShowAccountPicker();
	void QueSaveReplay();
	void SetFollowTarget2(PriWrapper InTarget);
	void FollowPlayer(PriWrapper InPlayer);
	void ClientSplitscreenJoinResponse(SteamID& PlayerID, unsigned long bAllow, std::string Error);
	void ServerRequestSplitscreenJoin(SteamID& PlayerID, std::string PlayerName);
	bool eventPreClientTravel(std::string PendingURL, uint8_t TravelType, unsigned long bIsSeamlessTravel);
	void NotifyGoalScored(int32_t ScoredOnTeam);
	void eventDestroyed();
	bool ShouldBeMuted(PlayerControllerWrapper Other);
	bool IsCommunicationFiltered(uint8_t Filter, PlayerControllerWrapper Other, unsigned long bPreset);
	void RefreshMutedPlayers(unsigned long bForceRefresh);
	void eventServerUnmutePlayer(SteamID& PlayerNetId);
	void eventServerMutePlayer(SteamID& PlayerNetId);
	void GameplayUnmutePlayer(SteamID& PlayerNetId);
	void GameplayMutePlayer(SteamID& PlayerNetId);
	void ServerSetChatFilter(uint8_t InVoiceFilter);
	void ServerSetVoiceFilter(uint8_t InVoiceFilter);
	bool IsExplictlyMuted(SteamID& PlayerNetId);
	void DebugAI();
	void SendPendingRPCs();
	bool CanSendMessage(unsigned long bQuickChatMessage);
	void ClientNotifyChatBanned(uint64_t ChatBanExpiration);
	void ClientNotifyChatDisabled(float Time);
	void ChatMessage_TA(PlayerReplicationInfoWrapper InPRI, std::string Message, uint8_t ChatChannel, unsigned long bPreset);
	void ServerSayInternal_TA(std::string Message, uint8_t ChatChannel, unsigned long bPreset);
	void ServerSay_TA(std::string Message, uint8_t ChatChannel, unsigned long bPreset);
	void Say_TA2(std::string Message, uint8_t ChatChannel, SteamID& Recipient, unsigned long bPreset);
	bool CanChatWith(PlayerControllerWrapper Other, unsigned long bPreset);
	bool AllowTextMessage(std::string msg);
	void PushToTalkEnd();
	void PushToTalk2();
	void HandleJoinGameMigrationCompleted(unsigned long bSuccess, std::string FailReason);
	void eventClientUnmutePlayer(SteamID& PlayerNetId);
	void eventClientMutePlayer(SteamID& PlayerNetId, unsigned long bAddToMuteList);
	void ClientSetOnlineStatus();
	void HandleGameDataSelected(int32_t PlaylistId, int32_t MutatorIndex);
	GameEventWrapper GetGameEvent();
	void ClientArbitratedMatchEnded();
	void BannedKick();
	void NoReservationKick();
	void IdleKick2();
	void ServerReportServer();
	void ClientUseItem(Vector& UseLocation, Rotator& UseRotation);
	void ServerTeleportCar(Vector& SpawnLocation, Rotator& NewRotation);
	void eventTeleportCar(Vector& SpawnLocation, Rotator& NewRotation);
	void ServerUsePickup(RBActorWrapper Target);
	void UsePickup2();
	void ToggleHandbrake(unsigned long bHandbrake);
	void ToggleBoost(unsigned long bBoost);
	void ToggleJump(unsigned long bJump);
	void TargetSelectLeft();
	void TargetSelectRight();
	void ReleaseRearCamera();
	void PressRearCamera();
	void ReleaseSecondaryCamera();
	void PressSecondaryCamera();
	void ReadyUp();
	void Spectate();
	void ChangeTeam(int32_t TeamNum);
	void SwitchTeam();
	void SetDefaultCameraMode();
	void ResetCameraMode();
	void ZeroMoveInput();
	void PlayerMove(float DeltaTime);
	void IgnoreMoveInput(unsigned long bNewMoveInput);
	void eventSendClientAdjustment();
	PlayerControllerWrapper GetPrimaryPlayerController();
	void HandleAddBoostComponent(BoostWrapper Boost);
	void ReplicateLoadout();
	void ReplicateCameraRotation();
	void SetUsingFreecam(unsigned long bFreecam);
	void SetUsingBehindView(unsigned long bBehindView);
	void SetUsingSecondaryCamera(unsigned long bSecondaryCamera);
	void ReplicateCameraSettings();
	void HandleControllerLayoutChanged(PriWrapper InPRI);
	void HandlePawnTypeChanged(PriWrapper InPRI);
	void HandlePendingViewCarSet(PriWrapper InPRI);
	void HandleReplaceBot(PriWrapper InPRI);
	void HandleTeamChanged(PriXWrapper InPRI);
	void HandleMatchEnded(ServerWrapper GameEvent);
	void HandleStartNewRound(ServerWrapper GameEvent);
	void HandleGameEventChanged(PriWrapper InPRI);
	void HandlePRICameraChanged(PriWrapper InPRI);
	void SetupLightBar();
	void HandlePersistentCameraSet(PriWrapper InPRI);
	void OnReceivedPlayerAndPRI();
	void UpdateVoiceFilter();
	void ReplicateLevelSessionID();
	void ServerInitInputBuffer(uint8_t Type);
	void eventReceivedPlayer();
	void eventPostBeginPlay();
	void EventChatMessage(PlayerControllerWrapper PC, std::string Message, unsigned long bPreset);
	void EventResetPlayer(PlayerControllerWrapper PC, unsigned long bFullReset);
	void EventSelectBallCamTarget(PlayerControllerWrapper PC, int32_t Direction);
	void EventTrainingEditorActorModified();
	void EventMuteChanged(PlayerControllerWrapper PC, SteamID& PlayerID, unsigned long bMuted);
	void EventLaunchControllerApplet();
	void EventLaunchAccountPicker(int32_t ControllerId);
    bool GetbUsingGamepad();
    void SetMouseSensitivity(float NewSensitivity);
    float GetMouseSensitivity();
	void SetAForward(float aForward);
	float GetAForward();
	void SetATurn(float aTurn);
	float GetATurn();
	void SetAStrafe(float aStrafe);
	float GetAStrafe();
	void SetAUp(float aUp);
	float GetAUp();
	void SetALookUp(float aLookUp);
	float GetALookUp();
    void SetLookRightScale(float NewScale);
    float GetLookRightScale();
    void SetLookUpScale(float NewScale);
    float GetLookUpScale();
    void SetGamepadLookScale(float NewScale);
    float GetGamepadLookScale();
    void SetALookRoll(float NewLookRoll);
    float GetALookRoll();
    void SetbRoll(bool NewRoll);
    bool GetbRoll();
	void SetSpectatorCameraAccel(float SpectatorCameraAccel);
	float GetSpectatorCameraAccel();
	void SetSpectatorCameraSpeed(float SpectatorCameraSpeed);
	float GetSpectatorCameraSpeed();

private:
	PIMPL
};