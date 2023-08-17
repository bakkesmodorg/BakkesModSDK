#pragma once
#include "CameraStateXWrapper.h"


struct FViewTargetTransitionParams;
struct FCameraOrientation;
struct FCameraTransition;

struct ViewTargetTransitionParams
{
	explicit ViewTargetTransitionParams(const FViewTargetTransitionParams&);
	explicit operator FViewTargetTransitionParams() const;

	float blend_time;
	unsigned char blend_function;/*ACamera_EViewTargetBlendFunction*/
	float blend_exp;
	bool lock_outgoing;
};


struct CameraOrientation
{
	explicit CameraOrientation(const FCameraOrientation&);
	explicit operator FCameraOrientation() const;

	Vector focus;
	Rotator rotation;
	float distance;
	float fov;
	Vector calculated_location;
};

struct CameraTransition
{
	explicit CameraTransition(const FCameraTransition&);
	explicit operator FCameraTransition() const;

	void* camera_state; //CameraStateWrapperX                                      	
	ViewTargetTransitionParams blend_params;
	float remaining_time;
	CameraOrientation snapshot_pov;
	bool started;
};

class BAKKESMOD_PLUGIN_IMPORT CameraStateBlenderWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(CameraStateBlenderWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD CameraStateXWrapper GetCameraState() const;
	_NODISCARD CameraTransition GetTransition() const;
	_NODISCARD void SetTransition(const CameraTransition& transition) const;

private:
	PIMPL
};
