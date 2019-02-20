#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include ".././GameObject/PlayerReplicationInfoWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT PriXWrapper : public PlayerReplicationInfoWrapper {
public:
	CONSTRUCTORS(PriXWrapper)

	//AUTO-GENERATED FROM FIELDS

	//AUTO-GENERATED FUNCTION PROXIES
	void eventDestroyed();
	void OnUniqueIdChanged();
	void SetUniqueId(SteamID& PlayerUniqueId);
	void UnregisterPlayerFromSession();
	void RegisterPlayerWithSession();
	void OnTeamChanged();
	void eventOnOwnerChanged();
	void eventSetPlayerName(std::string S);
	void EventDestroyed(PriXWrapper PRI);
	void EventTeamChanged(PriXWrapper PRI);
	void EventUniqueIdChanged(PriXWrapper PRI);
	void EventPlayerNameChanged(PriXWrapper PRI);
private:
	PIMPL
};