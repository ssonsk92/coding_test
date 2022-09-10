#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int zero_count = 0;
    int loop_count = 0;

    while ("1" != s)
    {
        loop_count++;

        int s_length = s.length();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        zero_count += s_length - s.length();
        s_length = s.length();

        s.clear();
        while (0 < s_length)
        {
            s += to_string(s_length % 2);
            s_length /= 2;
        }

        reverse(s.begin(), s.end());
    }

    answer.emplace_back(loop_count);
    answer.emplace_back(zero_count);

    return answer;
}

int main()
{
    vector<int> v = solution("110010101001");

    cout << v[0] << ", " << v[1] << endl;

    return 0;
}