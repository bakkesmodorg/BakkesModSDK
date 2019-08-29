#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././GameObject/RumbleComponent/RumblePickupComponentWrapper.h"
class RBActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT TornadoPickup : public RumblePickupComponentWrapper {
public:
	CONSTRUCTORS(TornadoPickup)

	//AUTO-GENERATED FROM FIELDS
	float GetHeight();
	void SetHeight(float newHeight);
	float GetRadius();
	void SetRadius(float newRadius);
	Vector GetOffset();
	void SetOffset(Vector newOffset);
	float GetRotationalForce();
	void SetRotationalForce(float newRotationalForce);
	float GetTorque();
	void SetTorque(float newTorque);
	Vector GetFXScale();
	void SetFXScale(Vector newFXScale);
	Vector GetFXOffset();
	void SetFXOffset(Vector newFXOffset);
	Vector GetMeshOffset();
	void SetMeshOffset(Vector newMeshOffset);
	Vector GetMeshScale();
	void SetMeshScale(Vector newMeshScale);
	float GetMaxVelocityOffset();
	void SetMaxVelocityOffset(float newMaxVelocityOffset);
	float GetBallMultiplier();
	void SetBallMultiplier(float newBallMultiplier);
	unsigned long GetbDebugVis();
	void SetbDebugVis(unsigned long newbDebugVis);
	float GetVelocityEase();
	void SetVelocityEase(float newVelocityEase);
	Vector GetVel();
	void SetVel(Vector newVel);
	ArrayWrapper<RBActorWrapper> GetAffecting();

	//AUTO-GENERATED FUNCTION PROXIES
	void ApplyForces(float ActiveTime);
	void PlayCarSFX(RBActorWrapper InActor);
	void PlayBallSFX(RBActorWrapper InActor);
private:
	PIMPL
};