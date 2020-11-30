#pragma once
#include "WrapperStructs.h"
#include "./Engine/ActorWrapper.h"
#include "ImageWrapper.h"


class BAKKESMOD_PLUGIN_IMPORT CanvasWrapper
{
public:
	CONSTRUCTORS(CanvasWrapper)

	void SetPosition(Vector2F pos);
	Vector2F GetPositionFloat();
	void SetColor(char Red, char Green, char Blue, char Alpha);//0-255
	void SetColor(LinearColor color);
	LinearColor GetColor();
	void DrawBox(Vector2F size);
	void FillBox(Vector2F size);
	void FillTriangle(Vector2F p1, Vector2F p2, Vector2F p3);
	void FillTriangle(Vector2F p1, Vector2F p2, Vector2F p3, LinearColor color);
	void DrawString(std::string text);
	void DrawString(std::string text, float xScale, float yScale);
	void DrawString(std::string text, float xScale, float yScale, bool dropShadow, bool wrapText=false);
    Vector2F GetStringSize(std::string text, float xScale=1, float yScale=1);
	void DrawLine(Vector2F start, Vector2F end);
	void DrawLine(Vector2F start, Vector2F end, float width);
	void DrawRect(Vector2F start, Vector2F end);
	void DrawTexture(ImageWrapper* img, float scale);
	void DrawRect(float RectX, float RectY, ImageWrapper* img);
	// don't ask. try..
	void DrawTile(ImageWrapper* img, float XL, float YL, float U, float V, float UL, float VL, LinearColor Color, unsigned int ClipTile, unsigned char Blend);
	void DrawRotatedTile(ImageWrapper* img, Rotator& Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	void DrawBox(Vector2 size);
	void FillBox(Vector2 size);
	void FillTriangle(Vector2 p1, Vector2 p2, Vector2 p3);
	void FillTriangle(Vector2 p1, Vector2 p2, Vector2 p3, LinearColor color);
	void DrawLine(Vector2 start, Vector2 end);
	void DrawLine(Vector2 start, Vector2 end, float width);
	void DrawRect(Vector2 start, Vector2 end);

	Vector2 Project(Vector location);
	Vector2F ProjectF(Vector location);
	Vector2 GetSize();
private:
	PIMPL
};
