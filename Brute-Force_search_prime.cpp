#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrimeNumber(int num)
{
    if (0 == num || 1 == num)
        return false;

    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (0 == (num % i))
            return false;
    }

    return true;
}

string strSwap(string str_num, int n1, int n2)
{
    char c1 = str_num[n1];
    char c2 = str_num[n2];

    string result = str_num;
    result[n1] = c2;
    result[n2] = c1;

    return result;
}

void permutation(string& numbers, vector<bool>& visit, vector<int>& order, int depth, int r, vector<int>& result)
{
    if (depth == r)
    {
        string number;
        for (int i = 0; i < r; i++)
        {
            number.push_back(numbers[order[i]]);
        }

        result.push_back(stoi(number));

        return;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (visit[i])
            continue;

        visit[i] = true;
        order[depth] = i;
        permutation(numbers, visit, order, depth + 1, r, result);
        visit[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    vector<int> result;
    for (int r = 1; r <= numbers.size(); ++r)
    {
        vector<bool> visit;
        vector<int> order;
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            visit.push_back(false);
            if (r <= order.size())
                continue;

            order.push_back(0);
        }

        permutation(numbers, visit, order, 0, r, result);
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    for (size_t i = 0; i < result.size(); ++i)
    {
        if (isPrimeNumber(result[i]))
            answer++;
    }

    return answer;
}

int main()
{
    string s("17");
    cout << solution(s) << endl;

    return 0;
}

https://school.programmers.co.kr/learn/courses/30/lessons/42839