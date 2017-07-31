#pragma once
#include "wrapperstructs.h"
#include <functional>
#include <memory>
extern class ActorWrapper;
typedef std::function<void(ActorWrapper, string, void* params)> EventCallback;

class BAKKESMOD_PLUGIN_IMPORT ActorWrapper
{
	
public:
	std::uintptr_t memory_address;
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
	
	void Freeze();
	void ListenForEvents(EventCallback callbackk, HookMode hm = HookMode_Pre); //Careful when using Post, might corrupt stack!
	//Not yet implemented unlisten
	void UnlistenForEvents(EventCallback cb);
	bool IsHooked();

	Vector GetAngularVelocity();
	void SetAngularVelocity(Vector v, bool addToCurrent=false);
	bool IsNull();

	Vector GetAccel();
	Rotator GetRotRate();


private:
	PIMPL
	
};

