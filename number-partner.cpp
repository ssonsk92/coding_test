#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    for (int i = 0; i <= 9; ++i)
    {
        char num = *to_string(i).c_str();
        auto it_x = X.find(num);
        auto it_y = Y.find(num);

        if (string::npos != it_x && string::npos != it_y)
        {
            int x_num_count = count(X.begin(), X.end(), num);
            int y_num_count = count(Y.begin(), Y.end(), num);

            int overlap_count = min(x_num_count, y_num_count);
            for (int i = 0; i < overlap_count; ++i)
                answer += num;
        }
    }

    if (0 == answer.size())
        return "-1";

    sort(answer.begin(), answer.end(), greater<char>());

    if ('0' == answer[0])
        return "0";

    return answer;
}

int main()
{
    cout << solution("100", "123450") << endl;

    return 0;
}