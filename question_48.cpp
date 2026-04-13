//
//  question_48.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/20.
//

#include "header.h"

void Solution_48::rotate(vector<vector<int>> &matrix)
{
    int n = (int)matrix.size();
    
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        int gap = n - i * 2 - 1;
        for (int j = 0; j < gap; j++)
        {
            int cur_row = 0 , cur_col = 0, next_row = i, next_col = i + j;
            int next_val = matrix[next_row][next_col];
            for (int k = 0; k < 4; k++)
            {
                cur_row = next_row;
                cur_col = next_col;
                next_row = next_col;
                if (k == 0)
                {
                    next_col = i + gap;
                }
                else if (k == 1)
                {
                    next_col = i + gap - j;
                }
                else if (k == 2)
                {
                    next_col = i;
                }
                else
                {
                    next_col = i + j;
                }
                int tmp = matrix[next_row][next_col];
                matrix[next_row][next_col] = next_val;
                next_val = tmp;
            }
        }
    }
}

void Solution_48::test()
{
    vector<vector<int>> matrix = {
        { 5, 1, 9, 11 },
        { 2, 4, 8, 10 },
        { 13, 3, 6, 7 },
        { 15, 14, 12, 16 },
    };
    
    rotate(matrix);
    
    for (const auto &row : matrix)
    {
        for (const auto &ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
