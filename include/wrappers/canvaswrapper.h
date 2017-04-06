#pragma once
#include "wrapperstructs.h"
#include "actorwrapper.h"
extern class CanvasWrapper;
typedef void(*DrawCallback) (CanvasWrapper);

class BAKKESMOD_PLUGIN_IMPORT CanvasWrapper
{
public:
	CanvasWrapper(std::uintptr_t mem);
	CanvasWrapper(const CanvasWrapper& other);
	CanvasWrapper& operator=(CanvasWrapper rhs);
	~CanvasWrapper();

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	void SetColor(char Red, char Green, char Blue, char Alpha);//0-255
	void DrawBox(Vector2 size);
	void FillBox(Vector2 size);
	void DrawString(string text);
	void DrawLine(Vector2 start, Vector2 end);
	void DrawRect(Vector2 start, Vector2 end);

private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;
};
