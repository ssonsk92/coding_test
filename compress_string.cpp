#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();

    string prev;
    string result;

    size_t cutting_length = 1;
    size_t idx = 0;
    int repeat_count = 1;
    while (cutting_length <= s.length())
    {
        result.clear();
        idx = 0;

        prev = s.substr(idx, cutting_length);
        idx = idx + cutting_length;
        while (idx < s.size())
        {
            string cutting_str = s.substr(idx, cutting_length);

            if (prev == cutting_str)
            {
                repeat_count++;
            }
            else
            {
                string prefix = (1 == repeat_count) ? "" : to_string(repeat_count);
                result += prefix + prev;
                repeat_count = 1;
            }

            prev = cutting_str;
            idx = idx + cutting_length;
        }

        string prefix = (1 == repeat_count) ? "" : to_string(repeat_count);
        result += prefix + prev;
        repeat_count = 1;

        cutting_length++;
        answer = min(answer, (int)result.length());
    }

    return answer;
}

int main()
{
    string s = "aabbaccc";
    cout << solution(s) << endl;

    return 0;
}