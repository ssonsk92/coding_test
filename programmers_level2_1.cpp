#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (size_t m = 0; m < arr1.size(); ++m)
    {
        vector<int> col;
        for (size_t n = 0; n < arr2[0].size(); ++n)
        {
            int val = 0;
            for (size_t k = 0; k < arr2.size(); ++k)
            {
                val += arr1[m][k] * arr2[k][n];
            }
            col.push_back(val);
        }
        answer.push_back(col);
    }

    return answer;
}

int main()
{

    vector<vector<int>> arr1 = { {1, 4}, {3, 2}, {4, 1} };
    vector<vector<int>> arr2 = { {3, 3}, {3, 3} };
    //vector<vector<int>> arr1 = { {2, 3, 2}, {4, 2, 4}, {3, 1, 4} };
    //vector<vector<int>> arr2 = { {5, 4, 3}, {2, 4, 1}, {3, 1, 1} };
    vector<vector<int>> result = solution(arr1, arr2);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << "]";
    }
    cout << endl;
}