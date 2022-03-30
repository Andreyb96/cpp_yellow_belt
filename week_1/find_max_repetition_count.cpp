#include <map>
#include <string>
#include <vector>
#include <cassert>

enum class Lang {
	DE, FR, IT
};

struct Region {
	std::string std_name;
	std::string parent_std_name;
	std::map<Lang, std::string> names;
	int64_t population;
};

bool operator==(const Region& lhs, const Region& rhs)
{
	return lhs.std_name == rhs.std_name
		&& lhs.parent_std_name == rhs.parent_std_name
		&& lhs.names == rhs.names
		&& lhs.population == rhs.population;
}

int FindMaxRepetitionCount(const std::vector<Region>& regions)
{
	auto maxValue = 1;
	for (auto i = 0; i < regions.size(); i++)
	{
		auto result = 1;
		for (auto j = 0; j < regions.size(); j++)
		{
			if (i != j && regions[i] == regions[j])
			{
				result++;
			}
		}
		maxValue = result > maxValue ? result : maxValue;
	}
	return maxValue;
}

int main() {
	assert(FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		},
		}) == 3);

	assert(FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Moscow",
			"Toulouse",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			31
		},
		}) == 1);

	return 0;
}
