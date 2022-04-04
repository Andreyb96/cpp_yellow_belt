#include "test_framework.h"
#include <algorithm>

std::vector<std::vector<int>> GetAllPermutations(int n)
{
	std::vector<std::vector<int>> result;

	auto v = std::vector<int>();
	for (auto i = 0; i < n; i++)
	{
		v.push_back(i + 1);
	}

	do 
	{
		result.push_back(v);
	} 
	while (std::next_permutation(v.begin(), v.end()));
	std::sort(result.begin(), result.end());
	return result;
}

void Test()
{
	Assert(GetAllPermutations(3) == std::vector<std::vector<int>>
		({ std::vector<int>({1, 2, 3})
			, std::vector<int>({1, 3, 2})
			, std::vector<int>({2, 1, 3})
			, std::vector<int>({2, 3, 1})
			, std::vector<int>({3, 1, 2})
			, std::vector<int>({3, 2, 1})
			}), "N == 3");
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