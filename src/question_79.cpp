//
//  question_79.cpp
//  LeetCode
//
//  Created by 周至 on 2025/8/27.
//

#include "header.h"

bool Solution_79::dfs(vector<vector<char>> &board, int x, int y, string &word, int idx)
{
    if (board[y][x] != word[idx])
    {
        return false;
    }
    if (idx == word.size() - 1)
    {
        return true;
    }
    
    const int offset[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
    char ch = board[y][x];
    board[y][x] = '#';
    for (int i = 0; i < 4; i++)
    {
        int x_ = x + offset[i][0], y_ = y + offset[i][1];
        if (x_ >= 0 && x_ < board[0].size() && y_ >= 0 && y_ < board.size() && board[y_][x_] != '#')
        {
            if (dfs(board, x_, y_, word, idx + 1))
            {
                board[y][x] = ch;
                return true;
            }
        }
    }
    board[y][x] = ch;
    
    return false;
}

bool Solution_79::exist(vector<vector<char>> &board, string word)
{
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[0].size(); x++)
        {
            if (dfs(board, x, y, word, 0))
            {
                return true;
            }
        }
    }
    
    return false;
}

void Solution_79::test(void)
{
    vector<vector<char>> board =
    {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' },
    };
    string word = "ABCCED";
    
    cout << exist(board, word) << endl;
}
