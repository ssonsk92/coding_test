#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    deque<int> dq;
    for (string str : operations)
    {
        auto pos = str.find(' ');
        string cmd = str.substr(0, pos);
        int num = stoi(str.substr(pos + 1));

        if ("I" == cmd)
        {
            dq.emplace_back(num);
            sort(dq.begin(), dq.end());
        }
        else if (!dq.empty())
        {
            if (1 == num)
            {
                dq.pop_back();
            }
            else
            {
                dq.pop_front();
            }
        }
    }

    if (dq.empty())
        return { 0, 0 };

    answer.emplace_back(dq.back());
    answer.emplace_back(dq.front());

    return answer;
}

int main()
{
    vector<string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<int> result = solution(operations);
    return 0;
}