#pragma once
#include "./Engine/ObjectWrapper.h"
#include "wrapperstructs.h"
#include <vector>
class BAKKESMOD_PLUGIN_IMPORT GuiManagerWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(GuiManagerWrapper);
	void* GetImGuiStyle();
	void* GetImGuiUserStyle();

private:
	PIMPL
};


