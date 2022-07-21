#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> min_heap_A(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> min_heap_B(B.begin(), B.end());


    while (!min_heap_A.empty())
    {
        int numA = min_heap_A.top();
        int maxB = 0;

        while (!min_heap_B.empty())
        {
            int numB = min_heap_B.top();
            if (numA < numB)
            {
                answer++;
                min_heap_B.pop();
                min_heap_A.pop();
                break;
            }
            else
            {
                min_heap_B.pop();
            }
        }

        if (min_heap_B.empty())
        {
            priority_queue<int, vector<int>, greater<int>> emptypq;
            min_heap_A.swap(emptypq);
        }
    }

    return answer;
}

int main()
{
    vector<int> A = { 5, 1, 3, 7 };
    vector<int> B = { 2, 2, 6, 8 };
    cout << solution(A, B) << endl;
}