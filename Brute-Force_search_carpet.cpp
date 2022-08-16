#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_brown_count(int w, int h)
{
    return (w * 2) + (h * 2) - 4;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; ++i)
    {
        if (yellow % i == 0)
        {
            int w = yellow / i + 2, h = i + 2;
            int brown_count = get_brown_count(w, h);
            if (brown_count == brown)
            {
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> v = solution(24, 24);
    cout << v[0] << ", " << v[1] << endl;
}