#include <vector>
#include <iostream>
#include <algorithm>

void PrintVectorPart(const std::vector<int>& numbers)
{
	auto itFirstNegative = std::find_if(numbers.begin(), numbers.end(),
		[](int number)
	{
		return number < 0;
	});

	auto it = itFirstNegative;

	while (it > numbers.begin())
	{
		std::cout << *(--it) << " ";
	}
}

int main() 
{
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	std::cout << std::endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 }); 
	std::cout << std::endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	std::cout << std::endl;
	return 0;
}