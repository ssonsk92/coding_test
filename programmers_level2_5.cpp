#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = n; 0 < i; --i)
    {
        int sum = 0;
        for (int j = i; 0 < j; --j)
        {
            sum += j;
            if (sum == n)
                answer++;
            else if (n < sum)
                break;
        }
    }

    return answer;
}

int main()
{
    cout << solution(15) << endl;
}