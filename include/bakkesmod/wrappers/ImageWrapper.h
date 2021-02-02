#pragma once
#include <string>
#include <memory>
#include "wrapperstructs.h"

#ifdef __cpp_lib_filesystem
#include <filesystem>
#endif

class BAKKESMOD_PLUGIN_IMPORT ImageWrapper
{
public:

	explicit ImageWrapper(std::string path, bool canvasLoad = false, bool ImGuiLoad = false);
	explicit ImageWrapper(std::wstring path, bool canvasLoad = false, bool ImGuiLoad = false);
#ifdef __cpp_lib_filesystem
	explicit ImageWrapper(std::filesystem::path path, bool canvasLoad = false, bool ImGuiLoad = false);
#endif
	// Don't make copies of this object!
	ImageWrapper(const ImageWrapper&) = delete;
	ImageWrapper& operator =(const ImageWrapper&) = delete;

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
#ifdef __cpp_lib_filesystem
	std::filesystem::path GetPathFs();
#endif
	std::wstring GetPathW();
	
	Vector2 GetSize();
	Vector2F GetSizeF();

private:
	PIMPL
};
