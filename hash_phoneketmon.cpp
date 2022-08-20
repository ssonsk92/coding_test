#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int selected_count = nums.size() / 2;
    set<int> s(nums.begin(), nums.end());

    if (s.size() < selected_count)
    {
        answer = s.size();
    }
    else
    {
        answer = selected_count;
    }


    return answer;
}


int main()
{
    vector<int> nums = { 3,3,3,2,2,4 };
    cout << solution(nums) << endl;

    return 0;
}