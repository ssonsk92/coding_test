#include <vector>
#include <iostream>

using namespace std;

bool isPrimeNumber(int num)
{
    if (num == 0 || num == 1)
        return false;

    for (size_t i = 2; i < num / 2; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}


void permutation(vector<int> nums, vector<bool> visit, int depth, vector<int> result, int& answer)
{
    if (3 == depth)
    {
        int sum = 0;
        for (int n : result)
            sum += n;

        if (isPrimeNumber(sum))
            answer++;

        return;
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (visit[i])
            continue;

        visit[i] = true;
        result[depth] = nums[i];
        permutation(nums, visit, depth + 1, result, answer);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<bool> visit(nums.size());
    vector<int> r(3);
    permutation(nums, visit, 0, r, answer);

    return answer;
}

int main()
{
    vector<int> nums = { 1,2,7,6,4 };
    cout << solution(nums) << endl;

    return 0;
}