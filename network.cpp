#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(n);
    queue<int> q;
    q.push(0);
    visit[0] = true;

    int start = 0;
    int count = 0;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (int i = 0; i < computers[n].size(); ++i)
        {
            if (false == visit[i] && computers[n][i])
            {
                computers[start][i] = 1;
                q.push(i);
                visit[i] = true;
            }
        }

        if (q.empty())
        {
            count++;
            for (int i = 0; i < computers[start].size(); ++i)
            {
                if (false == visit[i] && 0 == computers[start][i])
                {
                    q.push(i);
                    break;
                }
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<int> > computers = { {1, 1, 0, 0},{1, 1, 0, 0},{0, 0, 1, 1 },{0,0,1,1} };

    cout << solution(4, computers) << endl;

    return 0;
}