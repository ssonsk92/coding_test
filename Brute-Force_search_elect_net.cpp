#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dfs(vector<bool>& visit, const vector<vector<int>>& wires, vector<int>& nodes)
{
    int node_count = 0;
    stack<int> s;
    s.push(nodes[0]);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (false == visit[node])
        {
            visit[node] = true;
            node_count++;

            for (size_t i = 0; i < wires[node].size(); ++i)
            {
                s.push(wires[node][i]);
            }
        }
    }

    return node_count;
}

vector<vector<int>> sort_wires(int n, vector<vector<int>> wires)
{
    vector<vector<int>> sort_wires;
    sort_wires.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        sort_wires.push_back(vector<int>());
    }

    for (size_t i = 0; i < wires.size(); ++i)
    {
        vector<int> node = wires[i];
        int n1 = node[0] - 1;
        int n2 = node[1] - 1;
        sort_wires[n1].push_back(n2);
        sort_wires[n2].push_back(n1);
    }

    return sort_wires;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;

    for (size_t i = 0; i < wires.size(); ++i)
    {
        vector<bool> visit;
        visit.reserve(n);
        for (int j = 0; j < n; ++j)
        {
            visit.push_back(false);
        }

        vector<int> nodes;
        nodes.reserve(n - 1);
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;

            nodes.push_back(j);
        }

        vector<vector<int>> removed_wires = wires;
        removed_wires.erase(removed_wires.begin() + i);
        vector<vector<int>> sorted = sort_wires(n, removed_wires);

        int countA = dfs(visit, sorted, nodes);
        int countB = n - countA;
        int diff = abs(countA - countB);
        if (diff < answer)
        {
            answer = diff;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> wires = { {1,3} ,{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
    cout << solution(9, wires) << endl;

    return 0;
}