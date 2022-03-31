#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y)
{
	return x + y;
}

std::string Reverse(std::string s)
{
	auto copy = s;
	std::reverse(copy.begin(), copy.end());
	return copy;
}

void Sort(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
}