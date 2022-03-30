#include <map>
#include <string>
#include <cassert>

std::string& GetRefStrict(std::map<int, std::string>& m, int key)
{
	const auto& it = m.find(key);
	if (it == m.end())
	{
		throw std::runtime_error("Invalid map key");
	}
	return it->second;
}

int main() {
	std::map<int, std::string> m = { {0, "value"} };
	std::string& item = GetRefStrict(m, 0);
	item = "newvalue";
	assert(m.find(0)->second == item);

	return 0;
}