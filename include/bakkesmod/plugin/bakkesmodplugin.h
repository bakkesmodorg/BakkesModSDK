#pragma once
#include "bakkesmodsdk.h"
#include "bakkesmod\wrappers\cvarmanagerwrapper.h"
#include "bakkesmod\wrappers\gamewrapper.h"
#include <memory>

namespace BakkesMod {
	namespace Plugin {

		class BakkesModPlugin;
		typedef uintptr_t(*GetPluginFunc)();
		typedef void(*deleteFunc)();
		struct PluginInfo {
			short apiBuildVersion; //The bakkesmod API version this plugin was built for.
			const char* fileName; //The filename of the built DLL
			const char* className; //The classname of the plugin which is loaded
			const char* pluginName; //Name of the plugin, shown to the user
			const char* pluginVersion; //The version of the plugin, shown to the user
			const unsigned long pluginType; //The type of plugin, can be freeplay, soccar, replay etc
			GetPluginFunc initializeFunc; //The function that is called to construct the plugin
			deleteFunc delFunc;
		};

		typedef PluginInfo*(__stdcall *export_func)();

		//Default plugin stuff, which is api version and file path
#define BAKKESMOD_STANDARD_PLUGIN_STUFF \
    BAKKESMOD_PLUGIN_API_VERSION,       \
    __FILE__


#define BAKKESMOD_PLUGIN(classType, pluginName, pluginVersion, pluginType)     \
static std::shared_ptr<classType> singleton;\
	extern "C" { \
      BAKKESMOD_PLUGIN_EXPORT uintptr_t getPlugin()     \
      {                                                      \
                 \
          if(!singleton) {									 \
				singleton = std::shared_ptr<classType>(new classType());\
		  }													 \
          return reinterpret_cast<std::uintptr_t>(&singleton);                                  \
      }                                                      \
	  BAKKESMOD_PLUGIN_EXPORT void deleteMe() { \
			if(singleton) \
				singleton.reset();\
		}\
      BAKKESMOD_PLUGIN_EXPORT BakkesMod::Plugin::PluginInfo exports =  \
      {                                                      \
          BAKKESMOD_STANDARD_PLUGIN_STUFF,                   \
          #classType,                                        \
          pluginName,                                        \
          pluginVersion,                                     \
		  pluginType,										 \
          getPlugin,                                         \
		  deleteMe											 \
	  };                                                     \
	}


		class BAKKESMOD_PLUGIN_EXPORT BakkesModPlugin
		{
		public:
			std::shared_ptr<CVarManagerWrapper> cvarManager;
			std::shared_ptr<GameWrapper> gameWrapper;
			virtual void onLoad() {};

			//Unload stuff here, notifiers/cvars are automatically cleared.
			virtual void onUnload() {};
		};

	}
}

