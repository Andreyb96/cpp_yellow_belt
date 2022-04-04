#include <budget_starter.h>

#include <algorithm>

const std::string EARN = "Earn";
const std::string COMPUTE_INCOME = "ComputeIncome";
constexpr auto SPACE = ' ';
constexpr auto HYPHEN = '-';

namespace
{
	tm makeDate(int day, int month, int year)
	{
		tm ttm = { 0 };
		ttm.tm_mday = day;
		ttm.tm_mon = month - 1;
		ttm.tm_year = year - 1900;
		return ttm;
	}

	tm BuildDate(std::string dateStr)
	{
		auto it = dateStr.find(HYPHEN);
		auto year = std::stoi(dateStr.substr(0, it));
		dateStr = dateStr.substr(it + 1);
		it = dateStr.find(HYPHEN);
		auto month = std::stoi(dateStr.substr(0, it));
		auto day = std::stoi(dateStr.substr(it + 1));
		return makeDate(day, month, year);
	}

	std::string BuildDateStr(const tm& date)
	{
		return std::to_string(date.tm_year + 1900) + HYPHEN + std::to_string(date.tm_mon + 1) + HYPHEN + std::to_string(date.tm_mday);
	}
} //anonymos

int BudgetStarter::Process(const std::string& command)
{
	auto it = command.find(EARN);
	if (it != std::string::npos)
	{
		Earn(command.substr(it + EARN.size() + 1));
		return 0;
	}

	it = command.find(COMPUTE_INCOME);
	if (it != std::string::npos)
	{
		return ComputeIncome(command.substr(it + COMPUTE_INCOME.size() + 1));
	}
	return -1;
}

void BudgetStarter::Earn(const std::string& command)
{
	auto tmpStr = command;
	auto it = tmpStr.find(SPACE);
	auto startDate = tmpStr.substr(0, it);
	
	tmpStr = tmpStr.substr(it + 1);
	it = tmpStr.find(SPACE);
	auto endDate = tmpStr.substr(0, it);

	auto moneyAmount = std::stoi(tmpStr.substr(it + 1));
	time_t end = std::mktime(&BuildDate(endDate));

	auto numOfDays = 0;

	for (tm date = BuildDate(startDate); end >= mktime(&date); ++date.tm_mday)
	{
		numOfDays++;
	}

	auto moneyEarnedPerDay = moneyAmount / numOfDays;

	for (tm date = BuildDate(startDate); end >= mktime(&date); ++date.tm_mday)
	{
		auto dateStr = BuildDateStr(date);
		auto dateIt = _moneyAmountByDate.find(dateStr);
		if (dateIt == _moneyAmountByDate.end())
		{
			_moneyAmountByDate.insert({ dateStr, {date, moneyEarnedPerDay} });
		}
		else
		{
			dateIt->second.moneyEarned += moneyEarnedPerDay;
		}
	}
}

int BudgetStarter::ComputeIncome(const std::string& command)
{
	auto totalIncome = 0;
	auto tmpStr = command;
	auto it = tmpStr.find(SPACE);
	auto startDate = tmpStr.substr(0, it);

	tmpStr = tmpStr.substr(it + 1);
	it = tmpStr.find(SPACE);
	auto endDate = tmpStr.substr(0, it);

	time_t end = std::mktime(&BuildDate(endDate));

	for (tm date = BuildDate(startDate); end >= mktime(&date); ++date.tm_mday)
	{
		auto dateStr = BuildDateStr(date);
		auto dateIt = _moneyAmountByDate.find(dateStr);
		if (dateIt != _moneyAmountByDate.end())
		{
			totalIncome += dateIt->second.moneyEarned;
		}
	}

	return totalIncome;
}