#include "test_framework.h"

int GetDistinctRealRootCount(double a, double b, double c)
{
	auto discr = pow(b, 2) - 4 * a*c;
	if (discr == 0 || a == 0)
	{
		if (a == 0 && b == 0)
		{
			return 0;
		}
		return 1;
	}
	else if (discr > 0)
	{
		return 2;
	}
	return 0;
}

void Test()
{
	Assert(GetDistinctRealRootCount(1, 4, 4) == 1, "D == 0");
	Assert(GetDistinctRealRootCount(1, 5, 4) == 2, "D > 0");
	Assert(GetDistinctRealRootCount(1, 1, 1) == 0, "D < 0");
	Assert(GetDistinctRealRootCount(0, 1, 1) == 1, "a == 0");
	Assert(GetDistinctRealRootCount(0, 0, 1) == 0, "a == 0 and b == 0");
	Assert(GetDistinctRealRootCount(0, 1, 0) == 1, "a == 0 and c == 0");
	Assert(GetDistinctRealRootCount(1, 0, 1) == 0, "b == 0 and c > 0");
	Assert(GetDistinctRealRootCount(1, 0, -1) == 2, "b == 0 and c < 0");
	Assert(GetDistinctRealRootCount(1, 0, 0) == 1, "b == 0 and c == 0");
	Assert(GetDistinctRealRootCount(1, 1, 0) == 2, "c == 0");
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