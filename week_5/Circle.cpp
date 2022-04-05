#include "Circle.h"

constexpr auto PI = 3.14;

Circle::Circle(int radius) :
	Figure("Circle")
	, _radius(radius)
{

}
std::string Circle::Name()
{
	return _name;
}

int Circle::Perimeter()
{
	return 2 * PI * _radius;
}

int Circle::Area()
{
	return PI * pow(_radius, 2);
}