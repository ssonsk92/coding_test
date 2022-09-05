#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> num_list_1, vector<int> num_list_2) {
    int answer = -1;

    uint64_t sum_1 = accumulate(num_list_1.begin(), num_list_1.end(), 0);
    uint64_t sum_2 = accumulate(num_list_2.begin(), num_list_2.end(), 0);

    queue<int> q1;
    for (int n : num_list_1)
    {
        q1.push(n);
    }

    queue<int> q2;
    for (int n : num_list_2)
    {
        q2.push(n);
    }

    int loop_cnt = 0;
    for (int i = 0; i < num_list_1.size() + num_list_2.size(); ++i)
    {
        if (sum_1 < sum_2)
        {
            int n = q2.front();
            sum_2 -= n;
            q2.pop();

            sum_1 += n;
            q1.push(n);

            loop_cnt++;
        }
        else if (sum_1 > sum_2)
        {
            int n = q1.front();
            sum_1 -= n;
            q1.pop();

            sum_2 += n;
            q2.push(n);

            loop_cnt++;
        }
        else
        {
            answer = loop_cnt;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> queue1 = { 7 };
    vector<int> queue2 = { 2, 1 };


    cout << solution(queue1, queue2) << endl;

    return 0;
}