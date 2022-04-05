#include "Figure.h"

class Rect : public Figure
{
public:
	Rect(int width, int height);
	std::string Name() override;
	int Perimeter() override;
	int Area() override;
private:
	int _width;
	int _height;
};