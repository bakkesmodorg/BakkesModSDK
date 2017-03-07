#pragma once
#include "wrapperstructs.h"
class ActorWrapper;
typedef std::function<void(ActorWrapper, string)> EventCallback;

class BAKKESMOD_PLUGIN_IMPORT ActorWrapper
{
	
public:
	std::uintptr_t memory_address;
	ActorWrapper(std::uintptr_t mem);
	ActorWrapper(const ActorWrapper& other);
	ActorWrapper& operator=(ActorWrapper rhs);
	~ActorWrapper();
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
	void ListenForEvents(EventCallback callbackk);

	

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
	
};

