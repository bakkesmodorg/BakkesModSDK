#pragma once

namespace BakkesMod::Plugin
{
	class PluginSettingsWindow
	{
	public:
		virtual ~PluginSettingsWindow() = default;
		/// <summary>
		/// This is where you draw your settings gui. It will be drawn in the BakkesMod plugin tab.
		/// IMPORTANT: This runs in the render thread.
		/// So if you call any game function from the wrappers you're very likely to crash the game.
		/// Solve this by wrapping any game function calls in a gameWrapper->Execute to make it run in the game thread
		/// </summary>
		virtual void RenderSettings() = 0;
		virtual std::string GetPluginName() = 0;

		/// <summary>
		/// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
		/// </summary>
		/// <param name="ctx"></param>
		virtual void SetImGuiContext(uintptr_t ctx) = 0;
	};
}

