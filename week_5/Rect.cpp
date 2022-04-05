#include "Rect.h"

Rect::Rect(int width, int height) :
	Figure("Rectangle")
	, _width(width)
	, _height(height)
{}

std::string Rect::Name()
{
	return _name;
}

int Rect::Perimeter()
{
	return 2 * (_width + _height);
}

int Rect::Area()
{
	return _width * _height;
}