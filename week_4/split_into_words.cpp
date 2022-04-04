#include "test_framework.h"
#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string& s)
{
	std::vector<std::string> result;
	auto copyStr = s;
	auto it = copyStr.find(' ');
	while (it != std::string::npos)
	{
		result.push_back(copyStr.substr(0, it));
		copyStr = copyStr.substr(it + 1);
		it = copyStr.find(' ');
	}
	result.push_back(copyStr);
	return result;
}

void Test()
{
	Assert(SplitIntoWords("C Cpp Java Python") == std::vector<std::string>({
		"C" ,
		"Cpp" ,
		"Java" ,
		"Python" }), "SplitIntoWords");
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