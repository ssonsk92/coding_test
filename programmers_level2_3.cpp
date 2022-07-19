#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    for (size_t i = 0; i < land.size() - 1; ++i)
    {
        land[i + 1][0] += max(max(land[i][1], land[i][2]), land[i][3]);
        land[i + 1][1] += max(max(land[i][0], land[i][2]), land[i][3]);
        land[i + 1][2] += max(max(land[i][0], land[i][1]), land[i][3]);
        land[i + 1][3] += max(max(land[i][0], land[i][1]), land[i][2]);
    }

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}

int main()
{
    vector<vector<int> > land = { {1, 2, 3, 5},{5, 6, 7, 8},{4, 3, 2, 1 } };
    cout << solution(land) << endl;
}