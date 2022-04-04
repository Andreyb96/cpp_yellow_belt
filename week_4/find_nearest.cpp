#include "test_framework.h"
#include <algorithm>
#include <set>

std::set<int>::const_iterator FindNearestElement(
	const std::set<int>& numbers,
	int border)
{
	auto it = std::lower_bound(std::begin(numbers), std::end(numbers), border);
	int start;

	if (numbers.empty())
	{
		return std::end(numbers);
	}

	if (it == std::end(numbers))
	{
		return --std::end(numbers);
	}
	else
	{
		start = 2 * border - *it;
	}

	for (auto i = start; i < border; i++)
	{
		it = std::lower_bound(numbers.begin(), numbers.end(), i);
	}

	return it;
}

void Test()
{
	std::set<int> numbers = { 1, 4, 6 };
	Assert(*FindNearestElement(numbers, 0) == 1, "0");
	Assert(*FindNearestElement(numbers, 3) == 4, "3");
	Assert(*FindNearestElement(numbers, 5) == 4, "5");
	Assert(*FindNearestElement(numbers, 6) == 6, "6");
	Assert(*FindNearestElement(numbers, 100) == 6, "100");

	std::set<int> emptySet;
	Assert(FindNearestElement(emptySet, 8) == std::end(emptySet), "8");
}

void TestAll()
{
	TestRunner runner;
	runner.RunTest(Test, "All tests");
}

int main()
{
	TestAll();
	return 0;
}