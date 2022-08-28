#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<stack<int>> v(board.size());

    int idx = 0;
    for (int c = 0; c < board.size(); ++c)
    {
        for (int r = board.size() - 1; 0 <= r; r--)
        {
            int doll_number = board[r][c];
            if (0 == doll_number)
                break;
            v[idx].push(doll_number);
        }
        idx++;
    }

    stack<int> basket;
    for (size_t i = 0; i < moves.size(); ++i)
    {
        int p = moves[i] - 1;

        if (board.size() <= p)
            continue;

        if (v[p].empty())
            continue;

        int doll_number = v[p].top();
        v[p].pop();

        if (!basket.empty())
        {
            int top_doll_number = basket.top();
            if (top_doll_number == doll_number)
            {
                answer += 2;
                basket.pop();
            }
            else
            {
                basket.push(doll_number);
            }
        }
        else
        {
            basket.push(doll_number);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0} ,
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    cout << solution(board, moves) << endl;
}