//
//  question_54.cpp
//  LeetCode
//
//  Created by 周至 on 2024/11/1.
//

#include "header.h"

vector<int> Solution_54::spiralOrder(vector<vector<int>> &matrix)
{
    int row_num = (int)matrix.size(), col_num = (int)matrix[0].size();
    int loop_num = min((row_num + 1) / 2, (col_num + 1) / 2);
    vector<int> ret;
    
    for (int i = 0; i < loop_num; i++)
    {
        for (int j = i; j < col_num - i; j++)
        {
            ret.push_back(matrix[i][j]);
        }
        for (int j = i + 1; j < row_num - i; j++)
        {
            ret.push_back(matrix[j][col_num - i - 1]);
        }
        if ((i == loop_num - 1 && row_num < col_num && row_num % 2 == 1) ||
            (i == loop_num - 1 && row_num > col_num && col_num % 2 == 1))
        {
            break;
        }
        for (int j = col_num - i - 2; j >= i; j--)
        {
            ret.push_back(matrix[row_num - i - 1][j]);
        }
        for (int j = row_num - i - 2; j > i; j--)
        {
            ret.push_back(matrix[j][i]);
        }
    }
    
    return ret;
}

void Solution_54::test()
{
    vector<vector<int>> maxtrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    vector<int> ret = spiralOrder(maxtrix);
    
    for (const auto &num : ret)
    {
        cout << num << " ";
    }
}
