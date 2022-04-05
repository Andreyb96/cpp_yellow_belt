#include "INotifier.h"

class SmsNotifier : public INotifier
{
public:
	SmsNotifier(const std::string& phoneNumber);
	std::string Notify(const std::string& message) const override;
private:
	std::string _phoneNumber;
};