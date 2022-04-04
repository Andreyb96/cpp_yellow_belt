#include <string>
#include <map>

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name);
	void ChangeLastName(int year, const std::string& last_name);
	std::string GetFullName(int year);
private:
	std::map <int, std::string> _firstNames;
	std::map <int, std::string> _lastNames;
};
