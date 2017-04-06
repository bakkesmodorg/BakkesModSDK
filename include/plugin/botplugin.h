#pragma once
#include "bakkesmodplugin.h"

#include "../wrappers/wrapperstructs.h"
namespace bakkesmod {
	namespace plugin {
		class BAKKESMOD_PLUGIN_EXPORT BotPlugin :
			public BakkesModPlugin
		{
		public:
			virtual void on_tick(ControllerInput *input, CarWrapper *localCar, BallWrapper *ball) {}
		};

	}
}