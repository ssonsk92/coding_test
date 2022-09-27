#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s)
{
    if (1 == s.length() % 2)
        return 0;

    stack<char> st;
    st.push(s[0]);

    for (size_t i = 1; i < s.size(); ++i)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }

        char c = st.top();
        if (c == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    if (st.empty())
        return 1;

    return 0;
}