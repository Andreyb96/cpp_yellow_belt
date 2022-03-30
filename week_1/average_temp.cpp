#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> AverageTemp(const std::vector<int>& samples, int n, int& k)
{
	std::vector<int> result;
	int idx = 0;
	double averageTemp = std::accumulate(samples.begin(), samples.end(), 0) / n;
	for (auto elem : samples)
	{
		if (elem > averageTemp)
		{
			k++;
			result.push_back(idx);
		}
		idx++;
	}
	return result;
}

int main()
{
	int k = 0;
	assert(AverageTemp(std::vector<int>({ 5, 4, 1, -2, 7 }), 5, k) == std::vector<int>({ 0, 1, 4 }));
	assert(k == 3);

	k = 0;
	assert(AverageTemp(std::vector<int>({ 2, 2, 2, 2, 2 }), 5, k) == std::vector<int>());
	assert(k == 0);

	return 0;
}