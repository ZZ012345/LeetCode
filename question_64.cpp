//
//  question_64.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/8.
//

#include "header.h"

int Solution_64::minPathSum(vector<vector<int>> &grid)
{
    int width = (int)grid[0].size();
    int height = (int)grid.size();
    vector<vector<int>> dp(height + 1, vector<int>(width + 1, INT_MAX));
    
    dp[0][1] = 0;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i - 1][j - 1];
        }
    }
    
    return dp[height][width];
}

void Solution_64::test(void)
{
    vector<vector<int>> grid = {
        { 1, 3, 1 },
        { 1, 5, 1 },
        { 4, 2, 1 },
    };
    cout << minPathSum(grid) << endl;
}
