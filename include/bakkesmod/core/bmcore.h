#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
//#include "../imgui/imgui.h"
#include <tuple>

#define BMCORE_INTERNAL_IMPORT __declspec(dllimport)
#pragma comment (lib, "bakkesmod.lib")

#define RESULT_DECL void*const result

namespace BMCore
{
    
    BMCORE_INTERNAL_IMPORT std::tuple<int, ImFont*> LoadFont(std::string name, std::string path, int size, const ImFontConfig* fontConfig, const ImWchar* glyphRanges);
    BMCORE_INTERNAL_IMPORT ImFont* GetFont(std::string name);
    
}
