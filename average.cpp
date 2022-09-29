#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    for (int n : arr)
    {
        answer += n;
    }

    return answer / arr.size();
}

int main()
{
    vector<int> arr = { 1,2,3,4 };
    cout << solution(arr) << endl;
    return 0;
}