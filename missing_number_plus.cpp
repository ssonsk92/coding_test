#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i)
    {
        answer -= numbers[i];
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 1,2,3,4,6,7,8,0 };
    cout << solution(numbers) << endl;

    return 0;
};