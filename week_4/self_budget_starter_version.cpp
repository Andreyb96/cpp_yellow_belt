#include "test_framework.h"
#include "budget_starter.h"
#include <algorithm>

void Test()
{
	auto numDays = 5;
	BudgetStarter budget;
	budget.Process("Earn 2000-01-02 2000-01-06 20");
	Assert(budget.Process("ComputeIncome 2000-01-01 2001-01-01") == 20, "ComputeIncome 2000-01-01 2001-01-01");
	Assert(budget.Process("ComputeIncome 2000-01-01 2000-01-03") == 8, "ComputeIncome 2000-01-01 2000-01-03");
	budget.Process("Earn 2000-01-03 2000-01-03 10");
	Assert(budget.Process("ComputeIncome 2000-01-01 2001-01-01") == 30, "ComputeIncome 2000-01-01 2001-01-01");
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