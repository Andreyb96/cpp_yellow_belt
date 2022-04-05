#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c);
	std::string Name() override;
	int Perimeter() override;
	int Area() override;
private:
	int _a;
	int _b;
	int _c;
};