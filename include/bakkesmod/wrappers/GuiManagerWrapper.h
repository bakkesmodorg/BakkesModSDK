#pragma once
#include "./Engine/ObjectWrapper.h"
#include "wrapperstructs.h"
//#include "../imgui/imgui.h"
#include <tuple>

class BAKKESMOD_PLUGIN_IMPORT GuiManagerWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(GuiManagerWrapper);
	void* GetImGuiStyle();
	// Path is relative to "bakkesmod/data/fonts/"
	// the int is a status code
	// 0: fail
	// 1: queued for loading
	// 2: already loaded (ImFont*) will be a valid pointer.
	std::tuple<int, ImFont*> LoadFont(std::string name, std::string path, int size, const ImFontConfig* = nullptr, const ImWchar* = nullptr);
	// the core fonts are named: default and title
	ImFont* GetFont(std::string name);

private:
	PIMPL
};


