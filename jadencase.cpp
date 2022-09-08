#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFirstCharacter = true;
    for (char c : s)
    {
        if (' ' != c && true == isFirstCharacter)
        {
            c = toupper(c);
            isFirstCharacter = false;
        }
        else if (' ' == c)
        {
            isFirstCharacter = true;
        }
        else
        {
            c = tolower(c);
        }

        answer += c;
    }

    return answer;
}

int main()
{
    string s = "3p  unFollowed me";

    s = solution(s);
    cout << s << endl;

    return 0;
}