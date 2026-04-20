//
//  question_36.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/17.
//

#include "header.h"

bool Solution_36::isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<int>> row_nums(9, vector<int>(9, 0)); /* 每行表示数独中每行1～9是否出现 */
    vector<vector<int>> col_nums(9, vector<int>(9, 0)); /* 每行表示数独中每列1～9是否出现 */
    vector<vector<int>> square_nums(9, vector<int>(9, 0)); /* 每行表示数独中每个九宫格1～9是否出现 */
    
    /* 依次处理数独中的每个数 */
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char ch = board[i][j];
            if (!((ch >= '1') && (ch <= '9')))
            {
                continue;
            }
            
            int num = ch - '1';
            /* 判断行是否有效 */
            if (row_nums[i][num] > 0)
            {
                return false;
            }
            else
            {
                row_nums[i][num]++;
            }
            
            /* 判断列是否有效 */
            if (col_nums[j][num] > 0)
            {
                return false;
            }
            else
            {
                col_nums[j][num]++;
            }
            
            /* 判断九宫格是否有效 */
            int sqaure_idx = (i / 3) * 3 + (j / 3);
            if (square_nums[sqaure_idx][num] > 0)
            {
                return false;
            }
            else
            {
                square_nums[sqaure_idx][num]++;
            }
        }
    }
    
    return true;
}

void Solution_36::test(void)
{
    vector<vector<char>> board =
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    cout << isValidSudoku(board) <<endl;
}
