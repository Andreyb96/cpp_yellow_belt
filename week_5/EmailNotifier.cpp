#include "EmailNotifier.h"

namespace
{
	std::string SendEmail(const std::string& email, const std::string& message)
	{
		return "Send '" + message + "' to e-mail " + email;
	}
} //anonymos

EmailNotifier::EmailNotifier(const std::string& emailNumber) :
	_emailNumber(emailNumber)
{}

std::string EmailNotifier::Notify(const std::string& message) const
{
	return SendEmail(_emailNumber, message);
}