//
//  question_221.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/9.
//

#include "header.h"

int Solution_221::maximalSquare(vector<vector<char>> &matrix)
{
    int m = (int)matrix.size(), n = (int)matrix[0].size();
    vector<vector<int>> dp(m ,vector<int>(n, 0));
    int max_square = 0;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '0')
            {
                continue;
            }
            
            int up = (i >= 1) ? dp[i - 1][j] : 0;
            int left = (j >= 1) ? dp[i][j - 1] : 0;
            int up_left = (i >= 1 && j >= 1) ? dp[i - 1][j - 1] : 0;
            int min_len = min(min(up, left), up_left);
            dp[i][j] = min_len + 1;
            max_square = max(max_square, dp[i][j] * dp[i][j]);
        }
    }
    
    return max_square;
}

void Solution_221::test(void)
{
    vector<vector<char>> matrix =
    {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' },
    };
    
    cout << maximalSquare(matrix) << endl;
}
