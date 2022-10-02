#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (0 == n)
        return 0;

    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (0 == n % i)
            answer += i;
    }

    return answer;
}

int main()
{
    cout << solution(3000) << endl;
    return 0;
}