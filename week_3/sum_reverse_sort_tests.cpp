#include "sum_reverse_sort.h"
#include "test_framework.h"
#include <algorithm>

void TestSum()
{
	Assert(Sum(2, 2) == 4, "2 + 2");
	Assert(Sum(0, 0) == 0, "0 + 0");
	Assert(Sum(1, 2) == 3, "1 + 2");
}

void TestReverse()
{
	Assert(Reverse("abcdef") == "fedcba", "abcdef");
	Assert(Reverse("hello") == "olleh", "hello");
	Assert(Reverse("world") == "dlrow", "world");
}

void TestSort()
{
	{
		auto vec = std::vector<int>({ 5, 4, 3, 2, 1 });
		Sort(vec);
		Assert(vec == std::vector<int>({ 1, 2, 3, 4, 5 }), "5, 4, 3, 2, 1");
	}

	{
		auto vec = std::vector<int>({ 2, 1, 3, 5, 4 });
		Sort(vec);
		Assert(vec == std::vector<int>({ 1, 2, 3, 4, 5 }), "2, 1, 3, 5, 4");
	}

	{
		auto vec = std::vector<int>({ 1, 2, 3, 4, 5 });
		Sort(vec);
		Assert(vec == std::vector<int>({ 1, 2, 3, 4, 5 }), "1, 2, 3, 4, 5");
	}
}

void TestAll()
{
	TestRunner runner;
	runner.RunTest(TestSum, "TestSum");
	runner.RunTest(TestReverse, "TestReverse");
	runner.RunTest(TestSort, "TestSort");
}

int main()
{
	TestAll();
	return 0;
}