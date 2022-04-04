#include "test_framework.h"
#include <algorithm>

template <typename T>
void RemoveDuplicates(std::vector<T>& elements)
{
	auto elemSet = std::set<T>(elements.begin(), elements.end());
	elements = std::vector<T>(elemSet.begin(), elemSet.end());
}

void Test()
{
	std::vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
	RemoveDuplicates(v1);
	Assert(v1 == std::vector<int>({ 0, 1, 4, 6, 7 }), "Vector of ints");

	std::vector<std::string> v2 = { "C", "C++", "C++", "C", "C++" };
	RemoveDuplicates(v2);
	Assert(v2 == std::vector<std::string>({ "C", "C++" }), "Vector of strings");
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