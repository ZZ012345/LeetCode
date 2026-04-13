//
//  question_74.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/1.
//

#include "header.h"

bool Solution_74::searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row_num = (int)matrix.size(), col_num = (int)matrix[0].size();
    int left = 0, right = row_num * col_num - 1;
    
    while (left <= right)
    {
        int cur = (left + right) >> 1;
        int cur_val = matrix[cur / col_num][cur - cur / col_num * col_num];
        if (cur_val > target)
        {
            right = cur - 1;
        }
        else if (cur_val < target)
        {
            left = cur + 1;
        }
        else
        {
            return true;
        }
    }
    
    return false;
}

void Solution_74::test(void)
{
    vector<vector<int>> matrix =
    {
        { 1, 3, 5, 7 },
        { 10, 11, 16, 20 },
        { 23, 30, 34, 60 },
    };
    int target = 13;
    
    cout << searchMatrix(matrix, target) << endl;
}
