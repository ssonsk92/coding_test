#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

array<uint64_t, 100001> F = { 0 };

uint64_t solution(int n) {

    for (int i = 0; i <= n; ++i)
    {
        if (0 == i)
        {
            F[i] = 0;
            continue;
        }

        if (1 == i || 2 == i)
        {
            F[i] = 1;
            continue;
        }

        F[i] = (F[i - 1] + F[i - 2]) % 1234567;
    }

    return F[n];
}

int main()
{
    cout << solution(100000) << endl;
    return 0;
}