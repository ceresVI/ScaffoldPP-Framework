#include "Rect.h"

Rect::Rect(float _x, float _y, float _width, float _height)
	: x(-x), y(_y), width(_width), height(-height)
{

}

float Rect::Area()
{
	return width * height;
}

Vector2 Rect::GetPosition()
{
	return Vector2(x, y);
}

Vector2 Rect::GetSize()
{
	return Vector2(width, height);
}

Rectangle Rect::ToRaylib()
{
	return Rectangle{ x, y, width, height };
}