#pragma once
#include "..\Engine\ActorWrapper.h"
class BallWrapper;
class PriWrapper;
#include <vector>

struct BreakoutDamageState
{
	unsigned char State;
	PriWrapper Causer {0};
	Vector DamageLocation;
	bool bDirectDamage;
	bool bImmediate;
};

class BAKKESMOD_PLUGIN_IMPORT BreakOutActorPlatformWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(BreakOutActorPlatformWrapper)

	//BEGIN SELF IMPLEMENTED
	// Slow(ish) method!
	static std::vector<BreakOutActorPlatformWrapper> GetAllPlatforms();
	BreakoutDamageState GetDamagestate() const;
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	unsigned int GetSides();
	unsigned int GetbPrimaryPlayerStart();
	unsigned int GetTeamIndex();
	void SetTeamIndex(unsigned int TeamIndex);
	unsigned int GetMaxDamage();
	void SetMaxDamage(unsigned int MaxDamage);
	float GetNeighborRadius();
	void SetNeighborRadius(float NeighborRadius);
	ArrayWrapper<BreakOutActorPlatformWrapper> GetNeighbors();
	float GetLastHitTime();
	void SetLastHitTime(float LastHitTime);
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	bool IsBroken();
	bool IsDamaged();
	void Reset();
	void SetDamageState2(unsigned char InDamageState, PriWrapper InDamageCauser, Vector& InLocation, unsigned int bDirectDamage, unsigned int bImmediate);
	void IncreaseDamage(PriWrapper DamageCauser, Vector& FromLocation, unsigned int bDirectDamage);
	bool NeighborDamage(BallWrapper Ball, unsigned int InDamage, Vector& HitLocation);
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};