#include "SmsNotifier.h"

namespace
{
	std::string SendSms(const std::string& number, const std::string& message)
	{
		return "Send '" + message + "' to number " + number;
	}
} //anonymos

SmsNotifier::SmsNotifier(const std::string& phoneNumber) :
	_phoneNumber(phoneNumber)
{}

std::string SmsNotifier::Notify(const std::string& message) const
{
	return SendSms(_phoneNumber, message);
}