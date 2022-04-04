#include "test_framework.h"
#include <algorithm>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt rangeBegin, RandomIt rangeEnd,
	char prefix)
{
	auto left = std::lower_bound(rangeBegin, rangeEnd, std::string(1, prefix));
	auto nextPrefix = static_cast<char>(prefix + 1);
	auto right = std::lower_bound(rangeBegin, rangeEnd, std::string(1, nextPrefix));
	return { left, right };
}

void Test()
{
	const std::vector<std::string> sortedStrings = { "moscow", "murmansk", "vologda" };

	const auto mResult =
		FindStartsWith(std::begin(sortedStrings), std::end(sortedStrings), 'm');
	Assert(*mResult.first == "moscow", "moscow");
	Assert(*(mResult.second - 1) == "murmansk", "murmansk");

	const auto pResult =
		FindStartsWith(std::begin(sortedStrings), std::end(sortedStrings), 'p');
	Assert(pResult.first - std::begin(sortedStrings) == 2, "pResult.first");
	Assert(pResult.second - std::begin(sortedStrings) == 2, "pResult.second");

	const auto vResult =
		FindStartsWith(std::begin(sortedStrings), std::end(sortedStrings), 'v');
	Assert(*vResult.first == "vologda", "vologda");
	Assert(vResult.second == sortedStrings.end(), "vologda 2");

	const auto zResult =
		FindStartsWith(std::begin(sortedStrings), std::end(sortedStrings), 'z');

	Assert(zResult.first - std::begin(sortedStrings) == 3, "zResult.first");
	Assert(zResult.second - std::begin(sortedStrings) == 3, "zResult.second");
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