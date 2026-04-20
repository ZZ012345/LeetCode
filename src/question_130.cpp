//
//  question_130.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/19.
//

#include "header.h"

void dfs(vector<vector<char>> &board, int x, int y, char src, char dst)
{
    if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size())
    {
        return;
    }
    
    if (board[y][x] != src)
    {
        return;
    }
    
    board[y][x] = dst;
    dfs(board, x, y - 1, src, dst);
    dfs(board, x, y + 1, src, dst);
    dfs(board, x - 1, y, src, dst);
    dfs(board, x + 1, y, src, dst);
}

void Solution_130::solve(vector<vector<char>> &board)
{
    int width = (int)board[0].size();
    int height = (int)board.size();
    
    /* 替换边缘的'0'构成的区域 */
    for (int x = 0; x < width; x++)
    {
        if (board[0][x] == 'O')
        {
            dfs(board, x, 0, 'O', 'Y');
        }
        if (board[height - 1][x] == 'O')
        {
            dfs(board, x, height - 1, 'O', 'Y');
        }
    }
    for (int y = 0; y < height; y++)
    {
        if (board[y][0] == 'O')
        {
            dfs(board, 0, y, 'O', 'Y');
        }
        if (board[y][width - 1] == 'O')
        {
            dfs(board, width - 1, y, 'O', 'Y');
        }
    }
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (board[y][x] == 'Y')
            {
                board[y][x] = 'O';
            }
            else if (board[y][x] == 'O')
            {
                board[y][x] = 'X';
            }
        }
    }
}

void Solution_130::test(void)
{
    vector<vector<char>> board = {
        { 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'O', 'X' },
        { 'X', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'X' },
    };
    
    solve(board);
    
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[0].size(); x++)
        {
            cout << board[y][x] << " ";
        }
        cout << endl;
    }
}
