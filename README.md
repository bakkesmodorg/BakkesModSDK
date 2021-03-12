# BakkesModSDK
BakkesMod is a mod for Rocket League initially built as an enhancement for freeplay. Over time it has grown and now it features enhancements such as a dollycam, variance options to the in-game custom trainer, multiplayer game hosting, POV goal replays and much more.

BakkesMod also provides a software development kit/API which interfaces with Rocket League. For now it is mostly used for creating freeplay trainings and replay enhancements (such as analysis tools). The plan is to also extend the SDK so (limited) information can be retrieved from online games, which can be used to for example keep track of advanced statistics during gameplay.

Examples of plugins that are embedded with the mod when it is installed can be found [here](https://github.com/Bakkes/BakkesMod2-Plugins). The dollycam plugin is also open source and can be found [here](https://github.com/Bakkes/DollyCamPlugin2).

To get started using BakkesMod, simply go to http://bakkesmod.com and download the injector. If you wish to create plugins for the mod follow the steps that are described further down this page.

Currently the SDK is being extended to make it easier for plugin developers to create their own multiplayer gamemodes/training scenarios. BakkesMod has the ability to host an online game server which other players can connect to. For now only freeplay is supported but support for Team soccar/rumble is being added. Simply type "host" in the BakkesMod console to host a game, other players need to type "connect 127.0.0.1" to connect to your server (where 127.0.0.1 is your IP of course). In order for this to work you need to have forwarded port 27016 or use an utility such as Hamachi to emulate a LAN environment.

## Getting started
In order to create plugins for Rocket League with BakkesMod you need the SDK. By default the SDK will be included with the BakkesMod installation and can be found in [steamlibrary]\steamapps\common\rocketleague\Binaries\Win32\bakkesmod\bakkesmodsdk\. You could also simply clone this repository as this also contains the full SDK and is often more up to date.

Now create a new empty project in your IDE. Set the build target to Release Win64 and make sure it builds a (.dll). Now add the "include" folder of the BakkesMod SDK to the list of include folders of your project and add the pluginsdk.lib to your solution. Last up is to set your runtime library to "Multi-threaded (/MT)", in Visual Studio this will be under `Properties -> C/C++ -> Code Generation -> Runtime Library`. By default it will be set to "Multi-threaded DLL (/MD)" which needs to be changed.

There is also a Visual Studio project template that automatically creates a bare bones plugin for you which can be found [here](https://github.com/Martinii89/BakkesmodPluginTemplate/), this will give you an idea of how your plugin should be setup.

For examples on how to create plugins take a look at [the default plugins that come with the mod](https://github.com/Bakkes/BakkesMod2-Plugins) or browse the plugins hosted on [BakkesPlugins.com](https://bakkesplugins.com/) and see if they are open source. In order to load your plugin ingame make sure the generated .dll is placed in the plugins folder of BakkesMod. Next, in Rocket League open the console and type ```plugin load filename``` (without the .dll extension!). To unload your plugin you can use ```plugin unload filename```. Any cvars/notifiers/drawables that are registered when a plugin is loaded are automatically removed when a plugin is unloaded, so you don't have to worry about that!

More extensive documentation is in the making but for now hopefully the example plugins and header files should be mostly self explanatory. If you have any questions feel free to drop by the [BakkesMod Discord](https://discordapp.com/invite/HsM6kAR). There is a #programming channel where you can ask your questions. Alternatively, feel free to pm me on Discord at any time! (Bakkes#8746)