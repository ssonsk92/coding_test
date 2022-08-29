#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (size_t i = 0; i < absolutes.size(); ++i)
    {
        int n = absolutes[i];

        if (false == signs[i])
            n *= -1;

        answer += n;
    }

    return answer;
}

int main()
{
    vector<int> absolutes = { 4,7,12 };
    vector<bool> signs = { true,false,true };
    cout << solution(absolutes, signs) << endl;

    return 0;
}