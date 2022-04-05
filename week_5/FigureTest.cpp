#include "test_framework.h"
#include "Triangle.h"
#include "Rect.h"
#include "Circle.h"

#include <memory>
#include <iostream>
#include <iomanip>
#include <istream>

constexpr auto RECT = "RECT";
constexpr auto TRIANGLE = "TRIANGLE";
constexpr auto CIRCLE = "CIRCLE";

std::shared_ptr<Figure> CreateFigure(std::istringstream& is)
{
	std::string input;
	is >> input;

	if (input == RECT)
	{
		int width, height;
		is >> width;
		is >> height;
		return std::make_shared<Rect>(width, height);
	}

	if (input == TRIANGLE)
	{
		int a, b, c;
		is >> a;
		is >> b;
		is >> c;
		return std::make_shared<Triangle>(a, b, c);
	}

	if (input == CIRCLE)
	{
		int radius;
		is >> radius;
		return std::make_shared<Circle>(radius);
	}

	return nullptr;
}

int main() {
	std::vector<std::shared_ptr<Figure>> figures;
	for (std::string line; getline(std::cin, line); ) {
		std::istringstream is(line);

		std::string command;
		is >> command;
		if (command == "ADD") {
			is >> std::ws;
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				std::cout << std::fixed << std::setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << std::endl;
			}
		}
	}
	return 0;
}