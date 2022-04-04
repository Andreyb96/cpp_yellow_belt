#include <string>
#include <map>
#include <ctime>

struct MoneyByDate
{
	tm date;
	int moneyEarned;
};

class BudgetStarter
{
public:
	int Process(const std::string& command);
private:
	void Earn(const std::string& command);
	int ComputeIncome(const std::string& command);
private:
	std::map<std::string, MoneyByDate> _moneyAmountByDate;
};