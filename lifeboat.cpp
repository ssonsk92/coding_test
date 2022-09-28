#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {

    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());

    deque<int> dq(people.begin(), people.end());

    while (!dq.empty())
    {
        int w1 = dq.front();
        dq.pop_front();

        if (dq.empty())
        {
            answer++;
            break;
        }
        int w2 = dq.back();

        if (w1 + w2 <= limit)
        {
            dq.pop_back();
        }

        answer++;
    }

    return answer;
}

int main()
{
    vector<int> people = { 70 };
    cout << solution(people, 100) << endl;
    return 0;
}