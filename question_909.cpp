//
//  question_909.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/24.
//

#include "header.h"

int Solution_909::snakesAndLadders(vector<vector<int>> &board)
{
    int n = (int)board.size();
    vector<int> board_(n * n, 0), step(n * n, -1);
    
    bool direction = true;
    int cnt = 0;
    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = 0; col < n; col++)
        {
            board_[cnt++] = direction ? board[row][col] : board[row][n - col - 1];
        }
        direction = !direction;
    }

    int step_cnt = 0;
    step[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        step_cnt++;
        int size = (int)que.size();
        for (int i = 0; i < size; i++)
        {
            int cur = que.front();
            que.pop();
            
            for (int j = 1; j <= 6; j++)
            {
                if (cur + j < n * n)
                {
                    if (board_[cur + j] < 0 && step[cur + j] < 0)
                    {
                        step[cur + j] = step_cnt;
                        que.push(cur + j);
                    }
                    else if (board_[cur + j] > 0 && step[board_[cur + j] - 1] < 0)
                    {
                        step[board_[cur + j] - 1] = step_cnt;
                        que.push(board_[cur + j] - 1);
                    }
                }
            }
        }

        if (step[n * n - 1] > 0)
        {
            return step[n * n - 1];
        }
    }
    
    return step[n * n - 1];
}

void Solution_909::test(void)
{
    vector<vector<int>> board =
    {
        { -1, -1, 19, 10, -1 },
        { 2, -1, -1, 6, -1 },
        { -1, 17, -1, 19, -1 },
        { 25, -1, 20, -1, -1 },
        { -1, -1, -1, -1, 15 },
    };
    
    cout << snakesAndLadders(board) << endl;
}
