#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string str)
{
    bool answer = true;

    stack<char> s;

    auto iter = str.begin();
    while (iter != str.end())
    {
        if ('(' == *iter)
        {
            s.push('(');
        }
        else
        {
            if (s.empty())
            {
                return false;
            }

            s.pop();
        }

        ++iter;
    }

    if (!s.empty())
        return false;

    return answer;
}

int main()
{
    string s = "(()(";

    cout << solution(s) << endl;

    return 0;
}