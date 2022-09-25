#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    size_t max_h = citations.size();

    for (int h = max_h; 0 <= h; --h)
    {
        int cnt = count_if(citations.begin(), citations.end(), [&](int n) {return h <= n; });

        if (h <= cnt)
        {
            answer = h;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> citations = { 10, 10, 10, 10, 4 };
    //vector<int> citations = { 0, 0, 0, 0, 0 };
    //vector<int> citations = { 3, 0, 6, 1, 5 };
    cout << solution(citations) << endl;
    return 0;
}