#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int max_num = *max_element(arr.begin(), arr.end());

    int idx = 1;
    int answer = 0;
    while (answer <= numeric_limits<int>::max())
    {
        answer = max_num * idx;
        bool  isFInd = true;
        for (int n : arr)
        {
            if (0 < answer % n)
            {
                isFInd = false;
                idx++;
                break;
            }
        }

        if (isFInd)
            break;
    }

    return answer;
}

int main()
{
    vector<int> arr = { 2,6,8,14 };
    cout << solution(arr) << endl;
    return 0;
}