#pragma once
enum PLUGINTYPE {
	PLUGINTYPE_FREEPLAY = 0x01,
	PLUGINTYPE_CUSTOM_TRAINING = 0x02,
	PLUGINTYPE_SPECTATOR = 0x04,
	PLUGINTYPE_BOTAI = 0x08,
	PLUGINTYPE_REPLAY = 0x10,
	PLUGINTYPE_THREADED = 0x20,
	PLUGINTYPE_THREADEDUNLOAD = 0x40
};

//Permissions you can set for notifiers, 0x00 = ALL
enum NOTIFIER_PERMISSION {
	PERMISSION_ALL = 0,
	PERMISSION_MENU = (1 << 0),
	PERMISSION_SOCCAR = (1 << 1),
	PERMISSION_FREEPLAY = (1 << 2),
	PERMISSION_CUSTOM_TRAINING = (1 << 3),
	PERMISSION_ONLINE = (1 << 4),
	PERMISSION_PAUSEMENU_CLOSED = (1 << 5),
	PERMISSION_REPLAY = (1 << 6),
	PERMISSION_OFFLINE = (1 << 7) //Only when not in an online game
};

#ifdef _BAKKESMOD //Only define _BAKKESMOD if you're building bakkesmod, don't define it when building a plugin!
#define BAKKESMOD_PLUGIN_EXPORT
#define BAKKESMOD_PLUGIN_IMPORT __declspec(dllexport)
#else
#define BAKKESMOD_PLUGIN_EXPORT __declspec(dllexport)
#define BAKKESMOD_PLUGIN_IMPORT __declspec(dllimport)
#endif

#define BAKKESMOD_PLUGIN_API_VERSION 95
