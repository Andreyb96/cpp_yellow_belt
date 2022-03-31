#include "test_framework.h"

bool IsPalindrom(const std::string& str)
{
	return str == std::string(str.rbegin(), str.rend());
}

void Test()
{
	Assert(IsPalindrom("madam"), "madam");
	Assert(!IsPalindrom("gentleman"), "gentleman");
	Assert(IsPalindrom("X"), "X");
}

void TestAll()
{
	TestRunner runner;
	runner.RunTest(Test, "AllTests");
}

int main()
{
	TestAll();
	return 0;
}