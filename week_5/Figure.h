#include <string>
#pragma once

class Figure
{
public:
	Figure(const std::string& name) : _name(name) {}
	virtual std::string Name() = 0;
	virtual int Perimeter() = 0;
	virtual int Area() = 0;
protected:
	std::string _name;
};