#pragma once
#include "../wrappers/gamewrapper.h"
#include "../wrappers/consolewrapper.h"
#define BAKKESMOD_PLUGIN_API_VERSION 1


const unsigned char PLUGINTYPE_FREEPLAY = 0x01;
const unsigned char PLUGINTYPE_CUSTOM_TRAINING = 0x02;
const unsigned char	PLUGINTYPE_SPECTATOR = 0x04;
const unsigned char PLUGINTYPE_BOTAI = 0x08;
const unsigned char PLUGINTYPE_REPLAY = 0x10;
const unsigned char PLUGINTYPE_THREADED = 0x20;

namespace bakkesmod {
	namespace plugin {

		class BakkesModPlugin;

		typedef BakkesModPlugin* (*GetPluginFunc)();
		struct PluginDetails {
			int apiVersion;
			const char* fileName;
			const char* className;
			const char* pluginName;
			const char* pluginVersion;
			const unsigned long pluginType;
			GetPluginFunc initializeFunc;
		};

		typedef PluginDetails*(__stdcall *export_func)();

#define BAKKESMOD_STANDARD_PLUGIN_STUFF \
    BAKKESMOD_PLUGIN_API_VERSION,       \
    __FILE__

#define BAKKESMOD_PLUGIN(classType, pluginName, pluginVersion, pluginType)     \
	extern "C" { \
      BAKKESMOD_PLUGIN_EXPORT bakkesmod::plugin::BakkesModPlugin* getPlugin()     \
      {                                                      \
          static classType singleton;                        \
          return &singleton;                                 \
      }                                                      \
      BAKKESMOD_PLUGIN_EXPORT bakkesmod::plugin::PluginDetails exports =  \
      {                                                      \
          BAKKESMOD_STANDARD_PLUGIN_STUFF,                   \
          #classType,                                        \
          pluginName,                                        \
          pluginVersion,                                     \
		  pluginType,										 \
          getPlugin                                          \
	  };                                                     \
	}

		class BAKKESMOD_PLUGIN_EXPORT BakkesModPlugin
		{
		public:
			GameWrapper* gameWrapper;
			ConsoleWrapper* console;

		public:
			void setGameWrapper(GameWrapper* gw);
			void setConsole(ConsoleWrapper * cons);

			virtual void onLoad() {};
			virtual void onUnload() {};
		};
	}
}

