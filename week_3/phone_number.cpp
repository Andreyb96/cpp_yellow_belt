#include "phone_number.h"

PhoneNumber::PhoneNumber(const std::string& number)
{
	auto posCountry = number.find('+'); 
	auto posCity = number.find('-');
	auto posLocalNum = number.substr(posCity + 1).find('-');

	if (posCountry == std::string::npos)
	{
		throw std::invalid_argument("Cannot find country code in phone number");
	}

	if (posCity == std::string::npos)
	{
		throw std::invalid_argument("Cannot find city code in phone number");
	}

	if (posCountry == std::string::npos)
	{
		throw std::invalid_argument("Cannot find local number in phone number");
	}

	_countryCode = number.substr(posCountry + 1, posCity - (posCountry + 1));
	_cityCode = number.substr(posCity + 1, posLocalNum);
	_localNumber = number.substr(posCity + posLocalNum + 2);
}

std::string PhoneNumber::GetCountryCode() const
{
	return _countryCode;
}

std::string PhoneNumber::GetCityCode() const
{
	return _cityCode;
}

std::string PhoneNumber::GetLocalNumber() const
{
	return _localNumber;
}
