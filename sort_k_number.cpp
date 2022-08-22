#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto v : commands)
	{
		int s = v[0] - 1, e = v[1], k = v[2] - 1;
		vector<int> range;
		for (int i = s; i < e; ++i)
		{
			range.emplace_back(array[i]);
		}
		sort(range.begin(), range.end());
		answer.push_back(range[k]);
	}

	return answer;
}

int main()
{
	vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	vector<int> result = solution(arr, commands);

	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	return 0;
}