//
//  question_289.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/21.
//

#include "header.h"

bool is_dead()
{
    return false;
}

void Solution_289::gameOfLife(vector<vector<int>> &board)
{
    const int offset[8][2] = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { -1, 0 },
        { 1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };
    int row_num = (int)board.size(), col_num = (int)board[0].size();
    
    for (int row = 0; row < row_num; row++)
    {
        for (int col = 0; col < col_num; col++)
        {
            int live_num = 0, row_ = 0, col_ = 0;
            for (int k = 0; k < 8; k++)
            {
                row_ = row + offset[k][1];
                col_ = col + offset[k][0];
                if ((row_ >= 0 && row_ < row_num && col_ >= 0 && col_ < col_num) &&
                    (board[row_][col_] == 1 || board[row_][col_] == 2))
                {
                    live_num++;
                }
            }
            if (board[row][col] == 1)
            {
                if (live_num < 2 || live_num > 3)
                {
                    board[row][col] = 2;
                }
            }
            else if (live_num == 3)
            {
                board[row][col] = 3;
            }
        }
    }
    
    for (int row = 0; row < row_num; row++)
    {
        for (int col = 0; col < col_num; col++)
        {
            if (board[row][col] == 2)
            {
                board[row][col] = 0;
            }
            else if(board[row][col] == 3)
            {
                board[row][col] = 1;
            }
        }
    }
}

void Solution_289::test(void)
{
    vector<vector<int>> board = {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 1, 1, 1 },
        { 0, 0, 0 },
    };
    gameOfLife(board);
    for (const auto &row : board)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}
