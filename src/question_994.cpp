//
//  question_994.cpp
//  LeetCode
//
//  Created by 周至 on 2026/7/13.
//

#include "header.h"

int Solution_994::orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size(), cols = grid[0].size();
    int fresh_num = 0, minutes = -1;
    queue<pair<int, int>> que;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (grid[y][x] == 2) /* 烂橘子 */
            {
                que.push({y, x});
            }
            else if(grid[y][x] == 1) /* 新鲜橘子 */
            {
                fresh_num++;
            }
        }
    }

    if (fresh_num == 0)
    {
        return 0;
    }

    while (!que.empty())
    {
        int rotten_num =que.size();
        for (int i = 0; i < rotten_num; i++)
        {
            auto [y, x] = que.front();
            que.pop();

            for (int k = 0; k < 4; k++)
            {
                int x_ = x + dx[k];
                int y_ = y + dy[k];
                if (x_ >= 0 && x_ < cols && y_ >= 0 && y_ < rows && grid[y_][x_] == 1)
                {
                    grid[y_][x_] = 2;
                    fresh_num--;
                    que.push({y_, x_});
                }
            }
        }
        minutes++;
    }

    if (fresh_num != 0)
    {
        return -1;
    }

    return minutes;
}

void Solution_994::test(void)
{
    vector<vector<int>> grid =
    {
        { 2, 1, 1 },
        { 1, 1, 0 },
        { 0, 1, 1 },
    };

    cout << orangesRotting(grid) << endl;
}
