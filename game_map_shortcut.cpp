#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int width = 0, height = 0;
int dest_x = 0, dest_y = 0;

void print_map(int current_x, int current_y, vector<bool> visit, const vector<vector<int> >& maps)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (x == current_x && y == current_y)
                printf("в└");
            else if (0 == maps[y][x])
                printf("бс");
            else if (visit[y * width + x])
                printf("б█");
            else if (maps[y][x])
                printf("бр");
        }
        cout << endl;
    }
    cout << endl;
}

int solution(vector<vector<int> > maps)
{
    width = maps[0].size(), height = maps.size();
    dest_x = width - 1, dest_y = height - 1;

    vector<bool> visit(width * height);

    // bfs
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    int loop_count = 0;
    int crossroad_count = 1;
    int remain_pop_count = crossroad_count;
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        remain_pop_count--;

        if (0 == remain_pop_count)
        {
            remain_pop_count = crossroad_count;
            loop_count++;
        }
        int current_x = pos.first, current_y = pos.second;

        //print_map(current_x, current_y, visit, maps);

        int visit_idx = width * current_y + current_x;
        visit[visit_idx] = true;

        if (current_x == dest_x && current_y == dest_y)
        {
            //cout << "arrive destination " << loop_count << endl;
            return loop_count;
        }

        // right move
        int push_count = 0;
        int next_x = current_x + 1, next_y = current_y;
        int next_visit_idx = width * next_y + next_x;
        if (next_x < width && maps[next_y][next_x] && false == visit[next_visit_idx])
        {
            q.push(make_pair(next_x, next_y));
            push_count++;
            visit[next_visit_idx] = true;
        }

        // left move
        next_x = current_x - 1, next_y = current_y;
        next_visit_idx = width * next_y + next_x;
        if (0 <= next_x && maps[next_y][next_x] && false == visit[next_visit_idx])
        {
            q.push(make_pair(next_x, next_y));
            push_count++;
            visit[next_visit_idx] = true;
        }

        // down move
        next_x = current_x, next_y = current_y + 1;
        next_visit_idx = width * next_y + next_x;
        if (next_y < height && maps[next_y][next_x] && false == visit[next_visit_idx])
        {
            q.push(make_pair(next_x, next_y));
            push_count++;
            visit[next_visit_idx] = true;
        }

        // up move
        next_x = current_x, next_y = current_y - 1;
        next_visit_idx = width * next_y + next_x;
        if (0 <= next_y && maps[next_y][next_x] && false == visit[next_visit_idx])
        {
            q.push(make_pair(next_x, next_y));
            push_count++;
            visit[next_visit_idx] = true;
        }

        if (1 < push_count)
        {
            crossroad_count += push_count - 1;
        }
        else if (0 == push_count)
        {
            crossroad_count--;
        }
    }

    return -1;
}

int main()
{
    //vector<vector<int> > maps = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} };
    vector<int> v1;
    for (int i = 0; i < 100; ++i)
        v1.push_back(1);

    vector<vector<int> > maps;
    for (int i = 0; i < 100; ++i)
        maps.push_back(v1);

    cout << solution(maps) << endl;

    return 0;
}