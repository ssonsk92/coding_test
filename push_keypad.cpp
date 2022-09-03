#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> get_number_pos(int n)
{
    if (0 == n)
    {
        return make_pair(1, 3);
    }

    int x = (n - 1) % 3;
    int y = (n - 1) / 3;

    return make_pair(x, y);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> left_pos(0, 3);
    pair<int, int> right_pos(2, 3);
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        int n = numbers[i];
        if (1 == n || 4 == n || 7 == n)
        {
            answer += 'L';
            left_pos = get_number_pos(n);
            continue;
        }

        if (3 == n || 6 == n || 9 == n)
        {
            answer += 'R';
            right_pos = get_number_pos(n);
            continue;
        }

        pair<int, int> num_pos = get_number_pos(n);
        int left_distance = abs(left_pos.first - num_pos.first) + abs(left_pos.second - num_pos.second);
        int right_distance = abs(right_pos.first - num_pos.first) + abs(right_pos.second - num_pos.second);

        if (left_distance < right_distance)
        {
            answer += 'L';
            left_pos = num_pos;
        }
        else if (left_distance == right_distance)
        {
            if ("left" == hand)
            {
                answer += 'L';
                left_pos = num_pos;
            }
            else
            {
                answer += 'R';
                right_pos = num_pos;
            }
        }
        else
        {
            answer += 'R';
            right_pos = num_pos;
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };

    cout << solution(numbers, "left") << endl;

    return 0;
}