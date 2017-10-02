#pragma once
enum {
	PLUGINTYPE_FREEPLAY = 0x01,
	PLUGINTYPE_CUSTOM_TRAINING = 0x02,
	PLUGINTYPE_SPECTATOR = 0x04,
	PLUGINTYPE_BOTAI = 0x08,
	PLUGINTYPE_REPLAY = 0x10,
	PLUGINTYPE_THREADED = 0x20
};

#ifdef _BAKKESMOD //Only define _BAKKESMOD if you're building bakkesmod, don't define it when building a plugin!
#define BAKKESMOD_PLUGIN_EXPORT
#define BAKKESMOD_PLUGIN_IMPORT __declspec(dllexport) 
#else
#define BAKKESMOD_PLUGIN_EXPORT __declspec(dllexport) 
#define BAKKESMOD_PLUGIN_IMPORT __declspec(dllimport) 
#endif


#define BAKKESMOD_PLUGIN_API_VERSION 35