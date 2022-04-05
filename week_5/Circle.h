#include "Figure.h"

class Circle : public Figure
{
public:
	Circle(int radius);
	std::string Name() override;
	int Perimeter() override;
	int Area() override;
private:
	int _radius;
};