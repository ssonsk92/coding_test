#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int x = 2; x <= 1000000; ++x)
    {
        if (n % x == 1)
            return x;
    }

    return answer;
}

int main()
{
    cout << solution(10) << endl;

    return 0;
}