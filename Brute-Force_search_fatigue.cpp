#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	vector<int> lst_idx;
	lst_idx.reserve(dungeons.size());
	for (int i = 0; i < dungeons.size(); ++i)
	{
		lst_idx.push_back(i);
	}

	do
	{
		int remain_k = k;
		int clear_count = 0;
		for (int i = 0; i < lst_idx.size(); ++i)
		{
			int idx = lst_idx[i];
			vector<int> dungeon = dungeons[idx];
			if (remain_k < dungeon[0])
				break;

			remain_k -= dungeon[1];
			clear_count++;
		}

		answer = max(answer, clear_count);

	} while (next_permutation(lst_idx.begin(), lst_idx.end()));

	return answer;
}

int main(void)
{
	int k = 80;
	vector<vector<int>> dungeons = { {80, 20},{50, 40},{30, 10} };
	cout << solution(k, dungeons) << endl;

	return 0;
}