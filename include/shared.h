#pragma once
#ifdef IS_PLUGIN
#define BAKKESMOD_PLUGIN_EXPORT __declspec(dllexport) 
#define BAKKESMOD_PLUGIN_IMPORT __declspec(dllimport) 
#else
#define BAKKESMOD_PLUGIN_EXPORT
#define BAKKESMOD_PLUGIN_IMPORT __declspec(dllexport) 
#endif

#include <string>
#include <vector>
using namespace std;
typedef void(*CVarChange) (std::vector<std::string>);

enum HookMode {
	HookMode_Pre = 0,
	HookMode_Post = 1 // test this shiz
};