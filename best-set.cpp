#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void get_set(int n, int s, vector<int> v, int& multiple, vector<int>& answer)
{
    if (1 == n)
    {
        v.emplace_back(s);
        //for (int i : v)
        //    cout << i << ", ";
        //cout << endl;

        int m = accumulate(v.begin(), v.end(), 1, multiplies<int>());
        if (multiple < m)
        {
            answer = v;
            multiple = m;
        }

        return;
    }

    for (int i = v[v.size() - 1]; i < s - n; ++i)
    {
        vector<int> temp = v;
        temp.emplace_back(i);
        get_set(n - 1, s - i, temp, multiple, answer);
    }
}

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (s < n)
        return { -1 };

    int multiple = 1;
    for (int i = 1; i < s - n; ++i)
    {
        vector<int> v;
        v.emplace_back(i);
        get_set(n - 1, s - i, v, multiple, answer);
    }

    return answer;
}

int main()
{
    vector<int> v = solution(2, 9);

    cout << "result : ";
    for (int i : v)
        cout << i << ", ";
    cout << endl;

    return 0;
}