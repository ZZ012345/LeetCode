//
//  question_52.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/31.
//

#include "header.h"

const int offset[4][2] = { { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };

int find_queen_cnt(int k, int origin, vector<vector<int>> &chessboard)
{
    int n = (int)chessboard.size();
    int cnt = 0;
    
    if (k == 1)
    {
        for (int i = origin; i < n * n; i++)
        {
            int x = i / n;
            int y = i - x * n;
            if (chessboard[x][y] == 0)
            {
                return 1;
            }
        }
        return 0;
    }
    
    if (k + origin / n > n)
    {
        return 0;
    }
    
    for (int i = origin; i < n * n; i++)
    {
        int x = i / n;
        int y = i - x * n;
        if (chessboard[x][y] != 0)
        {
            continue;
        }
        
        /* 标记会被攻击的位置 */
        vector<vector<int>> vec;
        for (int j = 0; j < n; j++)
        {
            if (chessboard[x][j] == 0)
            {
                chessboard[x][j] = 1;
                vec.push_back({ x, j });
            }
            if (chessboard[j][y] == 0)
            {
                chessboard[j][y] = 1;
                vec.push_back({ j, y });
            }
        }
        for (int j = 0; j < 4; j++)
        {
            int new_x = x, new_y = y;
            while (true)
            {
                new_x += offset[j][0];
                new_y += offset[j][1];
                if ((new_x >= 0) && (new_x < n) &&
                    (new_y >= 0) && (new_y < n))
                {
                    if (chessboard[new_x][new_y] == 0)
                    {
                        chessboard[new_x][new_y] = 1;
                        vec.push_back({ new_x, new_y });
                    }
                }
                else
                {
                    break;
                }
            }
        }
        
#if 0
        cout << "before:" << endl;
        for (const auto &ele1 : chessboard)
        {
            for (const auto &ele2 : ele1)
            {
                cout << ele2 << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
#endif
        
        /* 递归 */
        cnt += find_queen_cnt(k - 1, i + 1, chessboard);
        
        /* 恢复被标记的位置 */
        for (const auto &index : vec)
        {
            chessboard[index[0]][index[1]] = 0;
        }
        
#if 0
        cout << "after:" << endl;
        for (const auto &ele1 : chessboard)
        {
            for (const auto &ele2 : ele1)
            {
                cout << ele2 << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
#endif
    }
    
    return cnt;
}

int Solution_52::totalNQueens(int n)
{
    vector<vector<int>> chessboard(n, vector<int>(n, 0));
    
    return find_queen_cnt(n, 0, chessboard);
}

void Solution_52::test(void)
{
    int n = 4;
    
    cout << totalNQueens(n) << endl;
}
