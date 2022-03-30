#include <map>
#include <vector>
#include <iostream>
#include <cassert>

template <typename Elem>
Elem Sqr(Elem value)
{
	return value * value;
}

template <typename Elem>
std::vector<Elem> Sqr(const std::vector<Elem>& vec)
{
	std::vector<Elem> result;

	for (const auto& elem : vec)
	{
		result.push_back(Sqr(elem));
	}

	return result;
}

template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& p)
{
	return { Sqr(p.first), Sqr(p.second) };
}

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& m)
{
	std::map<Key, Value> result;

	for (const auto& elem : m)
	{
		result.insert({ elem.first, Sqr(elem.second) });
	}

	return result;
}

int main() {
	std::vector<int> v = { 1, 2, 3 };
	assert(Sqr(v) == std::vector<int>({ 1, 4, 9 }));

	std::map<int, std::pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};

	auto sqrMap = Sqr(map_of_pairs);
	assert(sqrMap.find(4)->second == std::make_pair(4, 4));
	assert(sqrMap.find(7)->second == std::make_pair(16, 9));

	return 0;
}