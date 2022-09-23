#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_nums(int num)
{
    vector<int> result;
    if (0 == num)
    {
        result.emplace_back(0);
        return result;
    }

    while (0 < num)
    {
        int n = num % 10;
        num /= 10;
        result.emplace_back(n);
    }

    reverse(result.begin(), result.end());

    return result;
}

class Comp
{
public:
    Comp() {};
    bool operator()(int lhs, int rhs)
    {
        vector<int> left = get_nums(lhs);
        vector<int> right = get_nums(rhs);

        size_t left_idx = 0, right_idx = 0;
        while (left[left_idx] == right[right_idx])
        {
            if (left_idx == left.size() - 1 || right_idx == right.size() - 1)
            {
                return left[left_idx] < right[right_idx];
            }

            left_idx = min(++left_idx, left.size() - 1);
            right_idx = min(++right_idx, right.size() - 1);
        }

        return left[left_idx] > right[right_idx];
    }
};

string solution(vector<int> numbers) {
    string answer = "";

    int max_num = *max_element(numbers.begin(), numbers.end());
    if (0 == max_num)
        return "0";

    sort(numbers.begin(), numbers.end(), Comp());

    for (int num : numbers)
    {
        answer += to_string(num);
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 3, 30, 34, 5, 9 };
    //vector<int> numbers = { 979, 97, 978, 81, 818, 817 };
    //vector<int> numbers = {97, 978 };
    //vector<int> numbers = {42, 423, 34, 3, 30 };
    //vector<int> numbers = { 3, 33, 330 };
    cout << solution(numbers) << endl;
    return 0;
}