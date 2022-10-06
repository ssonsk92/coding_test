#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while (0 < n)
    {
        if ((a - 1) / 2 == (b - 1) / 2)
            break;

        a = (0 == a % 2) ? a / 2 : (a + 1) / 2;
        b = (0 == b % 2) ? b / 2 : (b + 1) / 2;
        n /= 2;
        answer++;
    }

    return answer;
}

int main()
{
    cout << solution(8, 1, 8) << endl;

    return 0;
}