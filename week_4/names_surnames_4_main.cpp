#include <cassert>

#include "names_surnames_4.h"
#include "test_framework.h"

void Test()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	Assert(person.GetFullName(1900) == "Incognito", "Incognito");
	Assert(person.GetFullName(1965) == "Polina with unknown last name", "Polina with unknown last name");
	Assert(person.GetFullName(1990) == "Polina Sergeeva", "Polina Sergeeva");

	person.ChangeFirstName(1970, "Appolinaria");
	Assert(person.GetFullName(1969) == "Polina Sergeeva", "Polina Sergeeva");
	Assert(person.GetFullName(1970) == "Appolinaria Sergeeva", "Appolinaria Sergeeva");

	person.ChangeLastName(1968, "Volkova");
	Assert(person.GetFullName(1969) == "Polina Volkova", "Polina Volkova");
	Assert(person.GetFullName(1970) == "Appolinaria Volkova", "Appolinaria Volkova");
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
