#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (int idx = left; idx <= right; ++idx)
    {
        int row_start_number = idx / n + 1;
        int mod_number = idx % n + 1;

        int val = max(row_start_number, mod_number);
        answer.push_back(val);
    }

    return answer;
}

int main()
{

    vector<int> v = solution(4, 7, 14);
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ", ";
    }

    cout << endl;
}