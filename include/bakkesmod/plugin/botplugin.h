#pragma once
//#include "bakkesmodplugin.h"

namespace BakkesMod {
	namespace Plugin {
		class BotPlugin// : public BakkesModPlugin
		{
			virtual void OnNewGameEvent(); //Clear your old data and register your new bots here!
			//TODO: find good cleanup
		};
	}
}