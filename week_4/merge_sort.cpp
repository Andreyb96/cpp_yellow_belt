#include "test_framework.h"
#include <algorithm>

template <typename RandomIt>
void MergeSortByTwoParts(RandomIt rangeBegin, RandomIt rangeEnd)
{
	if (rangeEnd - rangeBegin < 2)
	{
		return;
	}

	std::vector<typename RandomIt::value_type> elements(rangeBegin, rangeEnd);
	std::vector<typename RandomIt::value_type> beginVec =
		std::vector<typename RandomIt::value_type>(rangeBegin, rangeBegin + elements.size() / 2);
	std::vector<typename RandomIt::value_type> endVec =
		std::vector<typename RandomIt::value_type>(rangeBegin + elements.size() / 2, rangeEnd);
	MergeSortByTwoParts(beginVec.begin(), beginVec.end());
	MergeSortByTwoParts(endVec.begin(), endVec.end());
	std::merge(beginVec.begin(), beginVec.end(), endVec.begin(), endVec.end(), rangeBegin);
}

template <typename RandomIt>
void MergeSortByThreeParts(RandomIt rangeBegin, RandomIt rangeEnd)
{
	if (rangeEnd - rangeBegin < 2)
	{
		return;
	}

	std::vector<typename RandomIt::value_type> elements(rangeBegin, rangeEnd);
	std::vector<typename RandomIt::value_type> beginVec =
		std::vector<typename RandomIt::value_type>(rangeBegin, rangeBegin + elements.size() / 3);
	std::vector<typename RandomIt::value_type> middleVec =
		std::vector<typename RandomIt::value_type>(rangeBegin + elements.size() / 3, rangeBegin + 2 * elements.size() / 3);
	std::vector<typename RandomIt::value_type> endVec =
		std::vector<typename RandomIt::value_type>(rangeBegin + 2 * elements.size() / 3, rangeEnd);
	MergeSortByThreeParts(beginVec.begin(), beginVec.end());
	MergeSortByThreeParts(middleVec.begin(), middleVec.end());
	MergeSortByThreeParts(endVec.begin(), endVec.end());

	std::vector<typename RandomIt::value_type> tmpVec;
	std::merge(beginVec.begin(), beginVec.end(), middleVec.begin(), middleVec.end(), std::back_inserter(tmpVec));
	std::merge(tmpVec.begin(), tmpVec.end(), endVec.begin(), endVec.end(), rangeBegin);
}

void Test()
{
	std::vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSortByTwoParts(std::begin(v), std::end(v));
	Assert(v == std::vector<int>({ 0, 1, 4, 4, 4, 6, 6, 7, }), "MergeSortByTwoParts");

	v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSortByThreeParts(std::begin(v), std::end(v));
	Assert(v == std::vector<int>({ 0, 1, 4, 4, 4, 5, 6, 6, 7, }), "MergeSortByThreeParts");
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