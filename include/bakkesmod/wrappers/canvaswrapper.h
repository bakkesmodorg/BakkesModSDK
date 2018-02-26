#pragma once
#include "WrapperStructs.h"
#include "./Engine/ActorWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT CanvasWrapper
{
public:
	CONSTRUCTORS(CanvasWrapper)

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	void SetColor(char Red, char Green, char Blue, char Alpha);//0-255
	void DrawBox(Vector2 size);
	void FillBox(Vector2 size);
	void DrawString(string text);
	void DrawLine(Vector2 start, Vector2 end);
	void DrawRect(Vector2 start, Vector2 end);
	Vector2 Project(Vector location);
	Vector2 GetSize();
private:
	PIMPL
};
