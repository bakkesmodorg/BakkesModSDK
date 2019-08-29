#pragma once
#include "../plugin/bakkesmodplugin.h"
#include "./Engine/ObjectWrapper.h"
#include "wrapperstructs.h"
#include <vector>
class BAKKESMOD_PLUGIN_IMPORT PluginManagerWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(PluginManagerWrapper);
	std::vector<std::shared_ptr<BakkesMod::Plugin::LoadedPlugin>>* GetLoadedPlugins();

private:
	PIMPL
};

