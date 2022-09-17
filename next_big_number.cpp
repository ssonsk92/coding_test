#include <iostream>

using namespace std;

int get_one_count(int n)
{
    int count_1 = 0;
    int num = n;
    while (0 < num)
    {
        if (1 == (num % 2))
            count_1++;

        num /= 2;
    }

    return count_1;
}

int solution(int n) {
    int count_1 = get_one_count(n);

    int answer = n;

    while (count_1 != get_one_count(++answer));

    return answer;
}

int main()
{
    cout << solution(78) << endl;

    return 0;
}