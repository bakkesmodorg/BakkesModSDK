#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/RBActorWrapper.h"
class AIControllerWrapper;
class PlayerControllerWrapper;
class BoostWrapper;
class DodgeComponentWrapper;
class JumpComponentWrapper;
class PriWrapper;
class DoubleJumpComponentWrapper;
class VehicleSimWrapper;
class AirControlComponentWrapper;

class BAKKESMOD_PLUGIN_IMPORT VehicleWrapper : public RBActorWrapper {
public:
	CONSTRUCTORS(VehicleWrapper)


	unsigned long GetbCanJump();
	void SetbCanJump(unsigned long newbCanJump);
	

	//AUTO-GENERATED FROM FIELDS
	VehicleSimWrapper GetVehicleSim();
	void SetVehicleSim(VehicleSimWrapper newVehicleSim);
	StickyForceData GetStickyForce();
	void SetStickyForce(StickyForceData newStickyForce);
	unsigned long GetbDriving();
	void SetbDriving(unsigned long newbDriving);
	unsigned long GetbReplicatedHandbrake();
	void SetbReplicatedHandbrake(unsigned long newbReplicatedHandbrake);
	unsigned long GetbJumped();
	void SetbJumped(unsigned long newbJumped);
	unsigned long GetbDoubleJumped();
	void SetbDoubleJumped(unsigned long newbDoubleJumped);
	unsigned long GetbOnGround();
	void SetbOnGround(unsigned long newbOnGround);
	unsigned long GetbSuperSonic();
	void SetbSuperSonic(unsigned long newbSuperSonic);
	unsigned long GetbPodiumMode();
	void SetbPodiumMode(unsigned long newbPodiumMode);
	ControllerInput GetInput();
	void SetInput(ControllerInput newInput);
	unsigned char GetReplicatedThrottle();
	void SetReplicatedThrottle(unsigned char newReplicatedThrottle);
	unsigned char GetReplicatedSteer();
	void SetReplicatedSteer(unsigned char newReplicatedSteer);
    AIControllerWrapper GetAIController();
	PlayerControllerWrapper GetPlayerController();
	void SetPlayerController(PlayerControllerWrapper newPlayerController);
	PriWrapper GetPRI();
	void SetPRI(PriWrapper newPRI);
	int GetVehicleUpdateTag();
	void SetVehicleUpdateTag(int newVehicleUpdateTag);
	Vector GetLocalCollisionOffset();
	void SetLocalCollisionOffset(Vector newLocalCollisionOffset);
	Vector GetLocalCollisionExtent();
	void SetLocalCollisionExtent(Vector newLocalCollisionExtent);
	int GetLastBallTouchFrame();
	void SetLastBallTouchFrame(int newLastBallTouchFrame);
	int GetLastBallImpactFrame();
	void SetLastBallImpactFrame(int newLastBallImpactFrame);
	BoostWrapper GetBoostComponent();
	DodgeComponentWrapper GetDodgeComponent();
	AirControlComponentWrapper GetAirControlComponent();
	JumpComponentWrapper GetJumpComponent();
	DoubleJumpComponentWrapper GetDoubleJumpComponent();
	void SetDoubleJumpComponent(DoubleJumpComponentWrapper newDoubleJumpComponent);
	float GetTimeBelowSupersonicSpeed();
	void SetTimeBelowSupersonicSpeed(float newTimeBelowSupersonicSpeed);

	//AUTO-GENERATED FUNCTION PROXIES
	void ForceNetPacketIfNearBall();
	bool IsCarWithinForwardEllipticalCone(VehicleWrapper OtherCar, float YawAngleDegrees, float PitchAngleDegrees);
	float GetForwardSpeed();
	float GetTimeOffGround();
	float GetTimeOnGround();
	Vector GetGroundNormal();
	bool IsOnWall();
	bool IsOnGround();
	int GetNumWheelWorldContacts();
	int GetNumWheelContacts();
	void ZeroMovementVariables();
	void eventSetVehicleInput(ControllerInput& NewInput);
	void EnablePodiumMode();
	void SetDriving(unsigned long bDrive);
	void InitAudioParams();
	void OnPRIChanged();
	void OnControllerChanged();
	void UnPossessed();
	void EventPRIChanged(VehicleWrapper Vehicle);
private:
	PIMPL
};