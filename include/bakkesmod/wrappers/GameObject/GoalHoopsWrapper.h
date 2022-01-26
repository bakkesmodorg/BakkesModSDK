#pragma once
#include "GoalWrapper.h"
class ActorWrapper;


class BAKKESMOD_PLUGIN_IMPORT GoalHoopsWrapper : public GoalWrapper {
public:
	CONSTRUCTORS(GoalHoopsWrapper)

	//BEGIN SELF IMPLEMENTED
	//END SELF IMPLEMENTED

	//AUTO-GENERATED FROM FIELDS
	ActorWrapper GetBackboard();
	float GetRadius();
	Vector GetBackboardLocation();
	Vector GetBackboardDirection();
	//END AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FROM METHODS
	//END AUTO-GENERATED FROM METHODS

private:
	PIMPL
};