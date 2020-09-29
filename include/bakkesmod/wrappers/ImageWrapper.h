#pragma once
#include <string>
#include <memory>
#include "wrapperstructs.h"

class BAKKESMOD_PLUGIN_IMPORT ImageWrapper
{
public:
	ImageWrapper(std::string path, bool canvasLoad = false, bool ImGuiLoad = false);

	// Don't make copies of this object!
	ImageWrapper(const ImageWrapper&) = delete; 
	ImageWrapper& operator = (const ImageWrapper&) = delete; 

	//ImageWrapper(ImageWrapper&&) = default;
	//ImageWrapper& operator = (ImageWrapper&&) = default;

	~ImageWrapper();


	bool LoadForCanvas();
	bool IsLoadedForCanvas();
	// Will do the load procedure if it haven't been preloaded
	void* GetCanvasTex();

	void LoadForImGui(std::function<void(bool)> onLoaded);
	bool IsLoadedForImGui();
	// Will do the load procedure if it haven't been preloaded
	void* GetImGuiTex();

	std::string GetPath();
	Vector2 GetSize();
	Vector2F GetSizeF();

private:
	PIMPL
};