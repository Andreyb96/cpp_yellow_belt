#include "test_framework.h"
#include "arithmetic_expression.h"

void Test()
{
	auto numOps = 3;
	ArithmeticExpression expr(std::to_string(8));
	expr.AddOperation("* 3");
	expr.AddOperation("- 6");
	expr.AddOperation("/ 1");
	Assert(expr.GetExpression() == "(8 * 3 - 6) / 1", "(8 * 3 - 6) / 1");
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