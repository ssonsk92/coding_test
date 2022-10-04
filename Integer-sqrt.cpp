#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    long long i = 1;
    while (i * i <= 50000000000000LL)
    {
        if (n < i * i)
            return -1;
        else if (n == i * i)
            return (i + 1) * (i + 1);
    }

    return answer;
}

int main()
{
    cout << sqrt(3) * sqrt(3) << endl;

    return 0;
}