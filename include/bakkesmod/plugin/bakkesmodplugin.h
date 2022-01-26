#pragma once
#include "bakkesmod/wrappers/CVarManagerWrapper.h"
#include "bakkesmod/wrappers/GameWrapper.h"
#include "bakkesmodsdk.h"
#include <memory>
//#include <windows.h>

#ifndef _WINDEF_
class HINSTANCE__; // Forward or never
typedef HINSTANCE__* HINSTANCE;
#endif

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
				singleton = nullptr;\
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
            __pragma(warning(suppress:4251));
			std::shared_ptr<CVarManagerWrapper> cvarManager;
            __pragma(warning(suppress:4251));
			std::shared_ptr<GameWrapper> gameWrapper;
			virtual void onLoad() {};

			//Unload stuff here, notifiers/cvars are automatically cleared.
			virtual void onUnload() {};
		};


		struct LoadedPlugin {
			std::shared_ptr<PluginInfo> _details;
			std::shared_ptr<BakkesModPlugin> _plugin;
			HINSTANCE _instance;
			std::string _filename;
			std::shared_ptr<std::type_index> _typeid;

			LoadedPlugin(std::shared_ptr<PluginInfo> details, std::shared_ptr<BakkesModPlugin> plugin, HINSTANCE instance, std::string filename) {
				_details = details;
				_plugin = plugin;
				_instance = instance;
				_filename = filename;
				_typeid = std::make_shared<std::type_index>(typeid(*plugin));
			}
			~LoadedPlugin() {
				//_details.get()->delFunc();
				/*if (_instance)
					FreeLibrary(_instance);*/
			}
		};
	}
}
