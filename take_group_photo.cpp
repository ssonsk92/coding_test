#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;

    string friends = "ACFJMNRT";

    do
    {
        bool valid = true;
        for (size_t i = 0; i < data.size(); ++i)
        {
            string d = data[i];
            char friend_1 = d[0];
            char friend_2 = d[2];
            char condition = d[3];
            char condition_value = d[4] + 1;

            size_t friend_1_pos = friends.find(friend_1);
            size_t friend_2_pos = friends.find(friend_2);

            int distance = abs((int)friend_2_pos - (int)friend_1_pos);
            if (condition == '=')
            {
                if (atoi(&condition_value) != distance)
                {
                    valid &= false;
                    break;
                }
            }
            else if (condition == '<')
            {
                if (atoi(&condition_value) <= distance)
                {
                    valid &= false;
                    break;
                }
            }
            else if (condition == '>')
            {
                if (atoi(&condition_value) >= distance)
                {
                    valid &= false;
                    break;
                }
            }
        }

        if (valid)
        {
            answer++;
        }

    } while (next_permutation(friends.begin(), friends.end()));


    return answer;
}

int main()
{
    vector<string> data = { "N~F=0", "R~T>2" };

    cout << solution(2, data) << endl;

    return 0;
}