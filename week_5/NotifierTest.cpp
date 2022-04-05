#include "test_framework.h"
#include "SmsNotifier.h"
#include "EmailNotifier.h"

std::string Notify(INotifier& notifier, const std::string& message) 
{
	return notifier.Notify(message);
}

void Test()
{
	SmsNotifier sms{ "+7-495-777-77-77" };
	EmailNotifier email{ "na-derevnyu@dedushke.ru" };

	Assert(Notify(sms, "I have White belt in C++") == "Send 'I have White belt in C++' to number +7-495-777-77-77", "sms");
	Assert(Notify(email, "And want a Yellow one") == "Send 'And want a Yellow one' to e-mail na-derevnyu@dedushke.ru", "e-mail");
}

void TestAll()
{
	TestRunner runner;
	runner.RunTest(Test, "All tests");
}

int main()
{
	TestAll();
	return 0;
}