#include "INotifier.h"

class EmailNotifier : public INotifier
{
public:
	EmailNotifier(const std::string& emailNumber);
	std::string Notify(const std::string& message) const override;
private:
	std::string _emailNumber;
};