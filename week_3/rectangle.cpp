#include "rectangle.h"

Rectangle::Rectangle(int width, int height)
{
	_width = width;
	_height = height;
}

int Rectangle::GetArea() const
{
	return _width * _height;
}

int Rectangle::GetPerimeter() const 
{
	return 2 * (_width + _height);
}

int Rectangle::GetWidth() const
{ 
	return _width; 
}

int Rectangle::GetHeight() const 
{
	return _height; 
}