#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n)
        return { -1 };

    vector<int> answer(n);

    int t = s / n;
    int sum = s - (t * n);
    for (int i = 0; i < n; i++) {
        if (i >= n - sum)
            answer[i] = t + 1;
        else
            answer[i] = t;
    }
    return answer;
}

int main()
{
    vector<int> v = solution(4, 9);

    return 0;
}