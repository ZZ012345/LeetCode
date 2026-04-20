//
//  question_73.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/23.
//

#include "header.h"

void Solution_73::setZeroes(vector<vector<int>> &matrix)
{
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<int> rows(m ,0), cols(n, 0);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        if (rows[i] == 1)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (cols[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
}

void Solution_73::test(void)
{
    vector<vector<int>> matrix = {
        { 0, 1, 2, 0 },
        { 3, 4, 5, 2 },
        { 1, 3, 1, 5 },
    };
    setZeroes(matrix);
    for (const auto &row : matrix)
    {
        for (const auto &ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
