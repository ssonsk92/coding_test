#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);

    int valid_num_count = 0;
    for (int i = 0; i < 6; ++i)
    {
        int win_num = win_nums[i];
        auto find_it = find(lottos.begin(), lottos.end(), win_num);
        if (find_it != lottos.end())
        {
            valid_num_count++;
        }

    }

    ptrdiff_t unkown_count = count(lottos.begin(), lottos.end(), 0);
    int max_valid_count = unkown_count + valid_num_count;
    int min_valid_count = valid_num_count;

    answer[0] = min(6 - max_valid_count + 1, 6);
    answer[1] = min(6 - min_valid_count + 1, 6);

    return answer;
}

int main()
{
    vector<int> lottos = { 44, 1, 0, 0, 31, 25 }, win_nums = { 31, 10, 45, 1, 6, 19 };

    vector<int> result = solution(lottos, win_nums);

    return 0;
}