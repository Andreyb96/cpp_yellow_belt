#include "test_framework.h"
#include "budget_starter_plus.h"
#include <algorithm>

void Test()
{
	BudgetStarterPlus budget;
	budget.Process("2000-01-02 20");
	budget.Process("2000-01-06 10");
	budget.Process("2000-01-03 10");
	Assert(budget.Process("2000-01-01 2000-01-02") == 20, "2000-01-01 2000-01-02");
	Assert(budget.Process("2000-01-02 2000-01-06") == 40, "2000-01-02 2000-01-06");
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