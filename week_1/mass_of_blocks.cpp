#include <cassert>
#include <vector>
#include <numeric>

int SumVolume(const std::vector<std::vector<int>>& blocks, int density)
{
	auto result = 0;
	for (auto elem : blocks)
	{
		result += std::accumulate(
			elem.begin(),
			elem.end(),
			1,
			std::multiplies<int>());
	}
	return result * density;
}

int main()
{
	auto n = 2;
	auto density = 14;
	std::vector<std::vector<int>> blocks;
	blocks.push_back({ 1, 2, 3 });
	blocks.push_back({ 30, 40, 50 });

	assert(SumVolume(blocks, density) == 840084);

	return 0;
}