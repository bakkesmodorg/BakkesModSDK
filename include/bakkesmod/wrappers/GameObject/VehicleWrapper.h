#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/RBActorWrapper.h"
class BoostWrapper;
class DoubleJumpComponentWrapper;
class VehicleSimWrapper;
class DodgeComponentWrapper;
class JumpComponentWrapper;
class AirControlComponentWrapper;
class PriWrapper;

class BAKKESMOD_PLUGIN_IMPORT VehicleWrapper : public RBActorWrapper {
public:
	CONSTRUCTORS(VehicleWrapper)

	//AUTO-GENERATED FROM FIELDS
	VehicleSimWrapper GetVehicleSim();
	void SetVehicleSim(VehicleSimWrapper newVehicleSim);
	unsigned long GetbDriving();
	void SetbDriving(unsigned long newbDriving);
	unsigned long GetbReplicatedHandbrake();
	void SetbReplicatedHandbrake(unsigned long newbReplicatedHandbrake);
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
	PriWrapper GetPRI();
	void SetPRI(PriWrapper newPRI);
	int GetVehicleUpdateTag();
	void SetVehicleUpdateTag(int newVehicleUpdateTag);
	Vector GetLocalCollisionOffset();
	void SetLocalCollisionOffset(Vector newLocalCollisionOffset);
	Vector GetLocalCollisionExtent();
	void SetLocalCollisionExtent(Vector newLocalCollisionExtent);
	int GetLastHitBallFrame();
	void SetLastHitBallFrame(int newLastHitBallFrame);
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