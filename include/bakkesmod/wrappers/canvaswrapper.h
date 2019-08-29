#pragma once
#include "WrapperStructs.h"
#include "./Engine/ActorWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT CanvasWrapper
{
public:
	CONSTRUCTORS(CanvasWrapper)

	void SetPosition(Vector2F pos);
	Vector2F GetPositionFloat();
	void SetColor(char Red, char Green, char Blue, char Alpha);//0-255
	void DrawBox(Vector2F size);
	void FillBox(Vector2F size);
	void FillTriangle(Vector2F p1, Vector2F p2, Vector2F p3, LinearColor color);
	void DrawString(std::string text);
	void DrawString(std::string text, float xScale, float yScale);
	void DrawLine(Vector2F start, Vector2F end);
	void DrawLine(Vector2F start, Vector2F end, float width);
	void DrawRect(Vector2F start, Vector2F end);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	void DrawBox(Vector2 size);
	void FillBox(Vector2 size);
	void FillTriangle(Vector2 p1, Vector2 p2, Vector2 p3, LinearColor color);
	void DrawLine(Vector2 start, Vector2 end);
	void DrawLine(Vector2 start, Vector2 end, float width);
	void DrawRect(Vector2 start, Vector2 end);

	Vector2 Project(Vector location);
	Vector2 GetSize();
private:
	PIMPL
};
