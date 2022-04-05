#include <string>
#pragma once

class INotifier
{
public:
	virtual std::string Notify(const std::string& message) const = 0;
};