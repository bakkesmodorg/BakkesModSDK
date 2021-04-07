#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT PrimitiveComponentWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(PrimitiveComponentWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	unsigned char GetRBChannel();
	void SetRBChannel(unsigned char newRBChannel);
	unsigned char GetRBDominanceGroup();
	void SetRBDominanceGroup(unsigned char newRBDominanceGroup);
	unsigned long GetbOnlyBlockActorMovement();
	void SetbOnlyBlockActorMovement(unsigned long newbOnlyBlockActorMovement);
	unsigned long GetHiddenGame();
	void SetHiddenGame(unsigned long newHiddenGame);
	unsigned long GetbOwnerNoSee();
	void SetbOwnerNoSee(unsigned long newbOwnerNoSee);
	unsigned long GetbOnlyOwnerSee();
	void SetbOnlyOwnerSee(unsigned long newbOnlyOwnerSee);
	unsigned long GetbIgnoreOwnerHidden();
	void SetbIgnoreOwnerHidden(unsigned long newbIgnoreOwnerHidden);
	unsigned long GetbUseAsOccluder();
	void SetbUseAsOccluder(unsigned long newbUseAsOccluder);
	unsigned long GetbAllowApproximateOcclusion();
	void SetbAllowApproximateOcclusion(unsigned long newbAllowApproximateOcclusion);
	unsigned long GetbFirstFrameOcclusion();
	void SetbFirstFrameOcclusion(unsigned long newbFirstFrameOcclusion);
	unsigned long GetbIgnoreNearPlaneIntersection();
	void SetbIgnoreNearPlaneIntersection(unsigned long newbIgnoreNearPlaneIntersection);
	unsigned long GetbAcceptsStaticDecals();
	unsigned long GetbAcceptsDynamicDecals();
	unsigned long GetbIsRefreshingDecals();
	unsigned long GetCastShadow();
	void SetCastShadow(unsigned long newCastShadow);
	unsigned long GetbForceDirectLightMap();
	void SetbForceDirectLightMap(unsigned long newbForceDirectLightMap);
	unsigned long GetbCastDynamicShadow();
	void SetbCastDynamicShadow(unsigned long newbCastDynamicShadow);
	unsigned long GetbCastStaticShadow();
	void SetbCastStaticShadow(unsigned long newbCastStaticShadow);
	unsigned long GetbSelfShadowOnly();
	void SetbSelfShadowOnly(unsigned long newbSelfShadowOnly);
	unsigned long GetbNoModSelfShadow();
	void SetbNoModSelfShadow(unsigned long newbNoModSelfShadow);
	unsigned long GetbAcceptsDynamicDominantLightShadows();
	void SetbAcceptsDynamicDominantLightShadows(unsigned long newbAcceptsDynamicDominantLightShadows);
	unsigned long GetbCastHiddenShadow();
	void SetbCastHiddenShadow(unsigned long newbCastHiddenShadow);
	unsigned long GetbCastShadowAsTwoSided();
	void SetbCastShadowAsTwoSided(unsigned long newbCastShadowAsTwoSided);
	unsigned long GetbAcceptsLights();
	void SetbAcceptsLights(unsigned long newbAcceptsLights);
	unsigned long GetbAcceptsDynamicLights();
	void SetbAcceptsDynamicLights(unsigned long newbAcceptsDynamicLights);
	unsigned long GetbUseOnePassLightingOnTranslucency();
	void SetbUseOnePassLightingOnTranslucency(unsigned long newbUseOnePassLightingOnTranslucency);
	unsigned long GetbUsePrecomputedShadows();
	unsigned long GetbHasExplicitShadowParent();
	unsigned long GetCollideActors();
	void SetCollideActors(unsigned long newCollideActors);
	unsigned long GetAlwaysCheckCollision();
	void SetAlwaysCheckCollision(unsigned long newAlwaysCheckCollision);
	unsigned long GetBlockActors();
	void SetBlockActors(unsigned long newBlockActors);
	unsigned long GetBlockZeroExtent();
	void SetBlockZeroExtent(unsigned long newBlockZeroExtent);
	unsigned long GetBlockNonZeroExtent();
	void SetBlockNonZeroExtent(unsigned long newBlockNonZeroExtent);
	unsigned long GetCanBlockCamera();
	void SetCanBlockCamera(unsigned long newCanBlockCamera);
	unsigned long GetBlockRigidBody();
	void SetBlockRigidBody(unsigned long newBlockRigidBody);
	unsigned long GetbBlockFootPlacement();
	void SetbBlockFootPlacement(unsigned long newbBlockFootPlacement);
	unsigned long GetbDisableAllRigidBody();
	void SetbDisableAllRigidBody(unsigned long newbDisableAllRigidBody);
	unsigned long GetbSkipRBGeomCreation();
	void SetbSkipRBGeomCreation(unsigned long newbSkipRBGeomCreation);
	unsigned long GetbNotifyRigidBodyCollision();
	void SetbNotifyRigidBodyCollision(unsigned long newbNotifyRigidBodyCollision);
	unsigned long GetbFluidDrain();
	void SetbFluidDrain(unsigned long newbFluidDrain);
	unsigned long GetbFluidTwoWay();
	void SetbFluidTwoWay(unsigned long newbFluidTwoWay);
	unsigned long GetbIgnoreRadialImpulse();
	void SetbIgnoreRadialImpulse(unsigned long newbIgnoreRadialImpulse);
	unsigned long GetbIgnoreRadialForce();
	void SetbIgnoreRadialForce(unsigned long newbIgnoreRadialForce);
	unsigned long GetbIgnoreForceField();
	void SetbIgnoreForceField(unsigned long newbIgnoreForceField);
	unsigned long GetbUseCompartment();
	void SetbUseCompartment(unsigned long newbUseCompartment);
	unsigned long GetAlwaysLoadOnClient();
	void SetAlwaysLoadOnClient(unsigned long newAlwaysLoadOnClient);
	unsigned long GetAlwaysLoadOnServer();
	void SetAlwaysLoadOnServer(unsigned long newAlwaysLoadOnServer);
	unsigned long GetbIgnoreHiddenActorsMembership();
	void SetbIgnoreHiddenActorsMembership(unsigned long newbIgnoreHiddenActorsMembership);
	unsigned long GetAbsoluteTranslation();
	void SetAbsoluteTranslation(unsigned long newAbsoluteTranslation);
	unsigned long GetAbsoluteRotation();
	void SetAbsoluteRotation(unsigned long newAbsoluteRotation);
	unsigned long GetAbsoluteScale();
	void SetAbsoluteScale(unsigned long newAbsoluteScale);
	int GetVisibilityId();
	void SetVisibilityId(int newVisibilityId);
	Vector GetTranslation();
	void SetTranslation(Vector newTranslation);
	Rotator GetRotation();
	void SetRotation(Rotator newRotation);
	float GetScale();
	void SetScale(float newScale);
	Vector GetScale3D();
	void SetScale3D(Vector newScale3D);
	float GetBoundsScale();
	void SetBoundsScale(float newBoundsScale);
	void SetLastSubmitTime(float newLastSubmitTime);
	float GetLastRenderTime();
	float GetScriptRigidBodyCollisionThreshold();
	void SetScriptRigidBodyCollisionThreshold(float newScriptRigidBodyCollisionThreshold);

	//AUTO-GENERATED FUNCTION PROXIES
	void TermRBPhys();
	void InitRBPhys();
	void SetNotifyRigidBodyCollision(unsigned long bNewNotifyRigidBodyCollision);
	void SetRBChannel2(unsigned char Channel);
	void SetRBCollidesWithChannel(unsigned char Channel, unsigned long bNewCollides);
	void SetBlockRigidBody2(unsigned long bNewBlockRigidBody);
	void RetardRBLinearVelocity(Vector& RetardDir, float VelScale);
	void SetRBAngularVelocity(Vector& NewAngVel, unsigned long bAddToCurrent);
	void SetRBLinearVelocity(Vector& NewVel, unsigned long bAddToCurrent);
	void AddRadialForce(Vector& Origin, float Radius, float Strength, unsigned char Falloff);
	void AddRadialImpulse(Vector& Origin, float Radius, float Strength, unsigned char Falloff, unsigned long bVelChange);
private:
	PIMPL
};