#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ObjectWrapper.h"
class FXActorWrapper;
class ActorWrapper;
class UnrealStringWrapper;

class BAKKESMOD_PLUGIN_IMPORT GoalWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(GoalWrapper)

	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	//AUTO-GENERATED FROM FIELDS
	ActorWrapper GetGoalOrientation();
	void SetGoalOrientation(ActorWrapper newGoalOrientation);
	ArrayWrapper<ActorWrapper> GetOverrideGoalIndicatorOrientations();
	unsigned char GetTeamNum();
	void SetTeamNum(unsigned char newTeamNum);
	FXActorWrapper GetScoreFX();
	void SetScoreFX(FXActorWrapper newScoreFX);
	UnrealStringWrapper GetGoalIndicatorArchetype();
	unsigned long GetbNoGoalIndicator();
	void SetbNoGoalIndicator(unsigned long newbNoGoalIndicator);
	unsigned long GetbOnlyGoalsFromDirection();
	void SetbOnlyGoalsFromDirection(unsigned long newbOnlyGoalsFromDirection);
	unsigned long GetbShowFocusExtent();
	void SetbShowFocusExtent(unsigned long newbShowFocusExtent);
	ActorWrapper GetGoalDirection();
	void SetGoalDirection(ActorWrapper newGoalDirection);
	int GetPointsToAward();
	void SetPointsToAward(int newPointsToAward);
	Vector GetAutoCamFocusExtent();
	void SetAutoCamFocusExtent(Vector newAutoCamFocusExtent);
	Vector GetGoalFocusLocationOffset();
	void SetGoalFocusLocationOffset(Vector newGoalFocusLocationOffset);
	float GetMaxGoalScorerAttachRadius();
	void SetMaxGoalScorerAttachRadius(float newMaxGoalScorerAttachRadius);
	Vector GetGoalScoredDotDirection();
	void SetGoalScoredDotDirection(Vector newGoalScoredDotDirection);
	float GetMinAttachGoalToScorerDot();
	void SetMinAttachGoalToScorerDot(float newMinAttachGoalToScorerDot);
	Vector GetLocation();
	void SetLocation(Vector newLocation);
	Vector GetDirection();
	void SetDirection(Vector newDirection);
	Vector GetRight();
	void SetRight(Vector newRight);
	Vector GetUp();
	void SetUp(Vector newUp);
	Rotator GetRotation();
	void SetRotation(Rotator newRotation);
	Vector GetLocalExtent();
	void SetLocalExtent(Vector newLocalExtent);
	Vector GetWorldCenter();
	void SetWorldCenter(Vector newWorldCenter);
	Vector GetWorldExtent();
	void SetWorldExtent(Vector newWorldExtent);
	Vector GetWorldFrontCenter();
	void SetWorldFrontCenter(Vector newWorldFrontCenter);

	//AUTO-GENERATED FUNCTION PROXIES
	Vector GetGoalFocusExtentCenter();
	void Init();
	void eventBeginPlay();
private:
	PIMPL
};