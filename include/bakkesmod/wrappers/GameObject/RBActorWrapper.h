#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"
class FXActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT RBActorWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(RBActorWrapper)

	//AUTO-GENERATED FROM FIELDS
	float GetMaxLinearSpeed();
	void SetMaxLinearSpeed(float newMaxLinearSpeed);
	float GetMaxAngularSpeed();
	void SetMaxAngularSpeed(float newMaxAngularSpeed);
	unsigned long GetbDisableSleeping();
	void SetbDisableSleeping(unsigned long newbDisableSleeping);
	unsigned long GetbReplayActor();
	void SetbReplayActor(unsigned long newbReplayActor);
	unsigned long GetbFrozen();
	void SetbFrozen(unsigned long newbFrozen);
	unsigned long GetbIgnoreSyncing();
	void SetbIgnoreSyncing(unsigned long newbIgnoreSyncing);
	unsigned long GetbPhysInitialized();
	RBState GetOldRBState();
	void SetOldRBState(RBState newOldRBState);
	RBState GetRBState();
	void SetRBState(RBState newRBState);
	RBState GetReplicatedRBState();
	void SetReplicatedRBState(RBState newReplicatedRBState);
	RBState GetClientCorrectionRBState();
	void SetClientCorrectionRBState(RBState newClientCorrectionRBState);
	WorldContactData GetWorldContact();
	void SetWorldContact(WorldContactData newWorldContact);
	Vector GetSyncErrorLocation();
	float GetSyncErrorAngle();
	Vector GetSyncErrorAxis();
	FXActorWrapper GetFXActorArchetype();
	void SetFXActorArchetype(FXActorWrapper newFXActorArchetype);
	FXActorWrapper GetFXActor();
	void SetFXActor(FXActorWrapper newFXActor);
	int GetLastRBCollisionsFrame();
	RBActorWrapper GetWeldedActor();
	RBActorWrapper GetWeldedTo();
	float GetPreWeldMass();

	//AUTO-GENERATED FUNCTION PROXIES
	void SetMass(float NewMass);
	void SetConstrained3D(Vector& LinearLower, Vector& LinearUpper, Vector& AngularLower, Vector& AngularUpper);
	void SetConstrained2D(unsigned long bConstrain2D);
	void SetPhysicsState(RBState& NewState);
	void SetFrozen(unsigned long bEnabled);
	void SetMaxAngularSpeed2(float NewMaxSpeed);
	void SetMaxLinearSpeed2(float NewMaxSpeed);
	void AddTorque(Vector& Torque, unsigned char ForceMode);
	void AddForce(Vector& Force, unsigned char ForceMode);
	void UnWeldRBActor(RBActorWrapper Other);
	void WeldRBActor2(RBActorWrapper Other, Vector& WeldOffset, Rotator& WeldRotation);
	void ReInitRBPhys();
	void TerminateRBPhys();
	Vector GetCurrentRBLocation();
	RBState GetCurrentRBState();
	int GetPhysicsFrame();
	float GetPhysicsTime();
	void InitAk();
	void eventPreBeginPlay();
private:
	PIMPL
};