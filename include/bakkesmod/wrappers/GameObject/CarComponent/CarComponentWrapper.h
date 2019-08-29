#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../../WrapperStructs.h"
#include "../.././Engine/ActorWrapper.h"
class CarWrapper;
class PriWrapper;
class FXActorWrapper;
class VehicleWrapper;

class BAKKESMOD_PLUGIN_IMPORT CarComponentWrapper : public ActorWrapper {
public:
	CONSTRUCTORS(CarComponentWrapper)

	//AUTO-GENERATED FROM FIELDS
	FXActorWrapper GetFXActorArchetype();
	void SetFXActorArchetype(FXActorWrapper newFXActorArchetype);
	unsigned long GetbDisabled();
	void SetbDisabled(unsigned long newbDisabled);
	unsigned long GetbAutoActivate();
	void SetbAutoActivate(unsigned long newbAutoActivate);
	unsigned long GetbSimulateComponent();
	void SetbSimulateComponent(unsigned long newbSimulateComponent);
	unsigned long GetbCreated();
	void SetbCreated(unsigned long newbCreated);
	unsigned long GetbActive();
	void SetbActive(unsigned long newbActive);
	unsigned long GetbRemovedFromCar();
	void SetbRemovedFromCar(unsigned long newbRemovedFromCar);
	unsigned char GetComponentData();
	void SetComponentData(unsigned char newComponentData);
	unsigned char GetReplicatedActive();
	void SetReplicatedActive(unsigned char newReplicatedActive);
	PriWrapper GetActivator();
	void SetActivator(PriWrapper newActivator);
	VehicleWrapper GetVehicle();
	void SetVehicle(VehicleWrapper newVehicle);
	CarWrapper GetCar();
	void SetCar(CarWrapper newCar);
	float GetActivityTime();
	void SetActivityTime(float newActivityTime);
	float GetReplicatedActivityTime();
	void SetReplicatedActivityTime(float newReplicatedActivityTime);
	FXActorWrapper GetFXActor();
	void SetFXActor(FXActorWrapper newFXActor);

	//AUTO-GENERATED FUNCTION PROXIES
	void eventFellOutOfWorld();
	float GetInactiveTime();
	float GetActiveTime();
	void ApplyForces(float ActiveTime);
	void PrePhysicsStep(float DeltaTime);
	void RemoveFromCar();
	bool CanDeactivate();
	bool ConditionalDeactivate();
	bool CanActivate();
	bool ConditionalActivate();
	void SetActive(unsigned long bNewActive);
	void Deactivate2();
	void Activate2();
	void UnregisterCarEvents();
	void RegisterCarEvents();
	void HandleVehicleSetup(CarWrapper InCar);
	void OnVehicleSetupComplete();
	void Create2(CarWrapper OwnerCar, PriWrapper InActivator);
	void ClientUpdateActive();
	void EventActivationChanged(CarComponentWrapper CarComponent);
private:
	PIMPL
};