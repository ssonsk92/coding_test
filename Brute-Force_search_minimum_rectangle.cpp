#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_w = 0;
    int max_h = 0;

    for (size_t i = 0; i < sizes.size(); ++i)
    {
        vector<int> s = sizes[i];
        sort(s.begin(), s.end());

        max_w = max(max_w, s[0]);
        max_h = max(max_h, s[1]);
    }

    return max_w * max_h;
}


int main()
{
    vector<vector<int>> sizes = { {60, 50},{30, 70},{60, 30},{80, 40} };
    cout << solution(sizes) << endl;

    return 0;
}