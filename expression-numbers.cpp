#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = i; j <= n; ++j)
        {
            sum += j;
            if (n < sum)
                break;
            else if (n == sum)
                answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution(15) << endl;

    return 0;
}