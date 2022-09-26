#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int num = x;
    int sum = 0;
    while (0 < num)
    {
        sum += num % 10;
        num /= 10;
    }

    if (0 == x % sum)
        return true;

    return false;
}

int main()
{
    cout << solution(11) << endl;
    return 0;
}