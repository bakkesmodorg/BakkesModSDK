#pragma once
template<class T> class ArrayWrapper;
#include "../WrapperStructs.h"
#include ".././Engine/ObjectWrapper.h"
class ActorWrapper;

class BAKKESMOD_PLUGIN_IMPORT GoalWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(GoalWrapper)

	//AUTO-GENERATED FROM FIELDS
	ActorWrapper GetGoalOrientation();
	void SetGoalOrientation(ActorWrapper newGoalOrientation);
	ArrayWrapper<ActorWrapper> GetOverrideGoalIndicatorOrientations();
	unsigned char GetTeamNum();
	void SetTeamNum(unsigned char newTeamNum);
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
	Rotator GetRotation();
	void SetRotation(Rotator newRotation);
	Vector GetLocalMin();
	void SetLocalMin(Vector newLocalMin);
	Vector GetLocalMax();
	void SetLocalMax(Vector newLocalMax);
	Vector GetLocalExtent();
	void SetLocalExtent(Vector newLocalExtent);
	Vector GetWorldCenter();
	void SetWorldCenter(Vector newWorldCenter);
	Vector GetWorldExtent();
	void SetWorldExtent(Vector newWorldExtent);

	//AUTO-GENERATED FUNCTION PROXIES
	Vector GetGoalFocusExtentCenter();
	void eventBeginPlay();
private:
	PIMPL
};