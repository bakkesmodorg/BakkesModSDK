#pragma once
#include "actorwrapper.h"
#include "wrapperstructs.h"

class BoostWrapper;
class JumpWrapper;
class DoubleJumpWrapper;
class PriWrapper;
class VehicleSimWrapper;
class BAKKESMOD_PLUGIN_IMPORT CarWrapper : public ActorWrapper
{
public:
	CONSTRUCTORS(CarWrapper)

		//AUTO GENERATED
		GETSETH(bool, IsDriving)
		GETSETH(bool, IsOnGround)
		GETSETH(bool, HasJumped)
		GETSETH(bool, HasDoubleJumped)
		GETSETH(float, AddedBallForceMultiplier)
		GETSETH(bool, DisableGravity)
		GETSETH(bool, DemolishOnOpposingGround)
		GETSETH(bool, WasOnOpposingGround)
		GETSETH(bool, DemolishOnGoalZone)
		GETSETH(bool, WasInGoalZone)
		GETSETH(bool, OverrideHandbrakeOn)
		GETSETH(bool, OverrideBoostOn)
		GETSETH(float, AddedCarForceMultiplier)
		GETSETH(float, MaxTimeForDodge)
		GETSETH(float, LastWheelsHitBallTime)

		GETSETH(float, StickyForceGround)
		GETSETH(float, StickyForceWall)

		GETH(int, NumWheelContacts);
		GETH(int, NumWheelWorldContacts);
		GETH(Vector, GroundNormal)
		GETH(float, TimeOnGround)
		GETH(float, TimeOffGround)
		GETH(float, ForwardSpeed)
		GETH(bool, IsOnGround2)
		GETH(bool, IsOnWall)


		DoubleJumpWrapper GetDoubleJumpComponent();
		JumpWrapper GetJumpComponent();
	BoostWrapper GetBoost();
	PriWrapper GetPRI();
	VehicleSimWrapper GetVehicleSim();

	//SELF IMPLEMENTED
	bool IsBoostCheap();
	void SetBoostCheap(bool b);
	void SetCarRotation(Rotator rotation);
	void ForceBoost(bool force);
	string GetOwnerName();
	void Unfreeze();
	ControllerInput GetInput();
	void SetInput(ControllerInput input);
private:
	PIMPL
};

