#pragma once

#include <string>

class PhoneNumber {
public:
	explicit PhoneNumber(const std::string &number);

	std::string GetCountryCode() const;
	std::string GetCityCode() const;
	std::string GetLocalNumber() const;

private:
	std::string _countryCode;
	std::string _cityCode;
	std::string _localNumber;
};