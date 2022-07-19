#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(), scoville.end());

    while (min_heap.top() < K)
    {
        int first_scovile = min_heap.top();
        min_heap.pop();
        int second_scovile = min_heap.top();
        min_heap.pop();

        int result = first_scovile + second_scovile * 2;
        min_heap.push(result);

        if (min_heap.size() < 2)
        {
            if (min_heap.top() < K)
                return -1;
        }

        answer++;
    }

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;
    cout << solution(scoville, K) << endl;
}