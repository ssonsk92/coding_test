#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer;

    for (size_t i = 0; i < new_id.size(); ++i)
    {
        char c = new_id[i];

        if ('A' <= c && c <= 'Z')
        {
            new_id[i] = c + 'a' - 'A';
            answer += c + 'a' - 'A';
            continue;
        }

        bool isAlphabet = 'a' <= c && c <= 'z';
        bool isNumber = '0' <= c && c <= '9';
        bool isValidSpecial = '-' == c || '_' == c || '.' == c;

        if (!(isAlphabet || isNumber || isValidSpecial))
        {
            continue;
        }

        if (0 < answer.size() && '.' == answer[answer.size() - 1] && '.' == c)
        {
            continue;
        }

        answer += new_id[i];
    }

    if ('.' == answer[0])
    {
        answer = answer.substr(1);
    }

    if ("" == answer)
    {
        answer = 'a';
    }

    if (16 <= answer.size())
    {
        answer = answer.substr(0, 15);
    }

    if (0 < answer.size() && '.' == answer[answer.size() - 1])
    {
        answer = answer.substr(0, answer.size() - 1);
    }

    while (answer.size() <= 2)
    {
        answer += answer[answer.size() - 1];
    }

    return answer;
}

int main()
{
    string new_id = "#####";

    cout << solution(new_id) << endl;

    return 0;
}