#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ActorWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT FXActorWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(FXActorWrapper)

	//AUTO-GENERATED FROM FIELDS
	unsigned long GetbDeactivateWhenOwnerDestroyed();
	void SetbDeactivateWhenOwnerDestroyed(unsigned long newbDeactivateWhenOwnerDestroyed);
	unsigned long GetbAllowShadowCasting();
	void SetbAllowShadowCasting(unsigned long newbAllowShadowCasting);
	unsigned long GetbAutoActivate();
	void SetbAutoActivate(unsigned long newbAutoActivate);
	unsigned long GetbRenderInactive();
	void SetbRenderInactive(unsigned long newbRenderInactive);
	unsigned long GetbActive();
	void SetbActive(unsigned long newbActive);
	unsigned long GetbHadOwner();
	void SetbHadOwner(unsigned long newbHadOwner);
	FXActorWrapper GetParent();
	void SetParent(FXActorWrapper newParent);
	ActorWrapper GetAttachmentActor();
	void SetAttachmentActor(ActorWrapper newAttachmentActor);
	float GetDestroyWaitTime();
	void SetDestroyWaitTime(float newDestroyWaitTime);
	float GetDestroyTime();
	void SetDestroyTime(float newDestroyTime);
	int GetEditID();
	void SetEditID(int newEditID);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventDumpDebugInfo();
	void eventDestroyed();
	void Inherit(FXActorWrapper Other);
	void ResetParticles();
	void StopAllEffects();
	void eventDeactivateAndDestroy();
	void UpdateFXStates();
	bool IsLocallyControlled();
	void Deactivate2();
	void Activate2();
	void BindTo(FXActorWrapper ParentFXActor);
	void SetAttachmentActor2(ActorWrapper AttachToActor);
	void PostBeginPlay();
private:
	PIMPL
};