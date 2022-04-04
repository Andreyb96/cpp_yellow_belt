#include <algorithm>
#include <string>
#include <map>

#include <names_surnames_4.h>

namespace
{
	std::string FindNameByYear(const std::map<int, std::string>& m, int year)
	{
		auto it = m.upper_bound(year);

		if (it != m.begin())
		{
			return (--it)->second;
		}

		return "";
	}
} //anonymos

void Person::ChangeFirstName(int year, const std::string& first_name)
{
	auto it = _firstNames.find(year);
	if (it == _firstNames.end())
	{
		_firstNames.insert({ year, first_name });
	}
	else
	{
		it->second = first_name;
	}
}

void Person::ChangeLastName(int year, const std::string& last_name)
{
	auto it = _lastNames.find(year);
	if (it == _lastNames.end())
	{
		_lastNames.insert({ year, last_name });
	}
	else
	{
		it->second = last_name;
	}
}

std::string Person::GetFullName(int year)
{
	auto firstName = FindNameByYear(_firstNames, year);
	auto lastName = FindNameByYear(_lastNames, year);

	if (firstName.empty() && lastName.empty())
	{
		return "Incognito";
	}

	if (firstName.empty())
	{
		return lastName + " with unknown first name";
	}

	if (lastName.empty())
	{
		return firstName + " with unknown last name";
	}

	return firstName + " " + lastName;
}
