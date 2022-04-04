#include "test_framework.h"
#include <algorithm>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border)
{
	std::vector<T> result;
	
	for (auto elem : elements)
	{
		if (elem > border)
		{
			result.push_back(elem);
		}
	}

	return result;
}

void Test()
{
	Assert(FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5) == std::vector<int>({ 7, 8 }), "Set of ints");
	Assert(FindGreaterElements(std::set<std::string>{"C", "C++"}, std::string("Python")).size() == 0, "Set of strings");
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