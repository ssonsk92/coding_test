#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer;

    stringstream ss;
    ss.str(s);

    int n = 0;
    int max_num = INT32_MIN;
    int min_num = INT32_MAX;
    while (!ss.eof())
    {
        ss >> n;
        max_num = max(max_num, n);
        min_num = min(min_num, n);
    }

    answer = to_string(min_num) + " " + to_string(max_num);

    return answer;
}

int main()
{
    cout << solution("1 2 3 4") << endl;

    return 0;
}