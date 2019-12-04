#pragma once
#include <string>
namespace BakkesMod {
	namespace Plugin {
		class PluginWindow
		{
		public:
			/*
			Do ImGui rendering here
			*/
			virtual void Render() = 0; 

			/*
			Name of the menu that is used to toggle the window.
			*/
			virtual std::string GetMenuName() = 0;

			/*
			Title to give the menu
			*/
			virtual std::string GetMenuTitle() = 0;

			/*
			Don't call this yourself, BM will call this function with a pointer to the current ImGui context
			*/
			virtual void SetImGuiContext(uintptr_t ctx) = 0;

			/*
			Should events such as mouse clicks/key inputs be blocked so they won't reach the game
			*/
			virtual bool ShouldBlockInput() = 0;

			/*
			Return true if overlay which isn't interacted with
			*/
			virtual bool IsActiveOverlay() = 0;

			/*
			Called when window is opened
			*/
			virtual void OnOpen() = 0;

			/*
			Called when window is closed
			*/
			virtual void OnClose() = 0;
		};
	}
}