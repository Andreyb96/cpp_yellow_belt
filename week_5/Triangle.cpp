#include "Triangle.h"

Triangle::Triangle(int a, int b, int c) :
	Figure("Triangle")
	, _a(a)
	, _b(b)
	, _c(c)
{}

std::string Triangle::Name()
{
	return _name;
}

int Triangle::Perimeter()
{
	return _a + _b + _c;
}

int Triangle::Area()
{
	auto p = Perimeter();
	return sqrt(p * (p - _a) * (p - _b) * (p - _c));
}