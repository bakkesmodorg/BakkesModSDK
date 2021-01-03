#pragma once
#pragma warning(push)
#pragma warning(disable:4661)
#include "WrapperStructs.h"

class BAKKESMOD_PLUGIN_IMPORT UniqueIDWrapper
{
public:
	//Empty constructor so it can be declared in classes and we can have 0 values
	UniqueIDWrapper();
	UniqueIDWrapper(std::uintptr_t mem);
	UniqueIDWrapper(const UniqueIDWrapper& other);
	UniqueIDWrapper& operator=(UniqueIDWrapper rhs);
	~UniqueIDWrapper();

	OnlinePlatform GetPlatform() const;
	std::string GetEpicAccountID() const;
	unsigned long long GetUID() const;
	unsigned char GetSplitscreenID() const;

	/*
	String representation of the ID.
	Will be the EpicID if nonempty. Uid otherwise
	*/
	std::string str() const;
	/// <summary>
	/// Returns the id in the following format platform|accountId|splitScreenId
	/// </summary>
	/// <returns></returns>
	std::string GetIdString() const;
public:
	/*
	Not 100% with the internals here, think it depends on what the game reads. 
	For some functionality you might get away with just the epicAccountID, others might rely on UID & platform.
	And some others you might even need both. 
	AKA: it's best you just retrieve this wrapper from the game from existing players instead of using this function.
	This wrapper is an exception to most other wrappers, as in: you're allowed to store this one! woohoo
	*/
	static UniqueIDWrapper FromEpicAccountID(std::string epicAccountID, unsigned long long uid, OnlinePlatform platform, unsigned char splitscreenID = 0);

	bool operator <(const UniqueIDWrapper& rhs) const;
	bool operator==(const UniqueIDWrapper& rhs) const;
	bool operator!=(const UniqueIDWrapper& rhs) const;
protected:
	PIMPL
};

#pragma warning(pop)