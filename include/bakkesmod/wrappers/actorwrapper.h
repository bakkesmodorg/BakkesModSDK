#pragma once
#include "bakkesmod/plugin/bakkesmodsdk.h"
#include "objectwrapper.h"
#include "wrapperstructs.h"
#include <functional>
#include <memory>
#include <string>
using namespace std;
extern class ActorWrapper;
typedef std::function<void(ActorWrapper, string, void* params)> EventCallback;

class BAKKESMOD_PLUGIN_IMPORT ActorWrapper : public ObjectWrapper
{
	
public:
	
	CONSTRUCTORS(ActorWrapper)

	Vector GetLocation();
	void SetLocation(Vector location);

	Vector GetVelocity();
	void SetVelocity(Vector velocity);
	void AddVelocity(Vector velocity);

	Rotator GetRotation();
	void SetRotation(Rotator rotation);

	void SetTorque(Vector torq);

	void Stop();

	bool IsHooked();

	Vector GetAngularVelocity();
	void SetAngularVelocity(Vector v, bool addToCurrent=false);
	bool IsNull();

	Vector GetAccel();
	Rotator GetRotRate();


private:
	PIMPL
	
};

