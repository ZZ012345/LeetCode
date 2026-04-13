//
//  question_63.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/8.
//

#include "header.h"

int Solution_63::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = (int)obstacleGrid.size(), n = (int)obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];
    }
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = obstacleGrid[0][i] ? 0 : dp[0][i - 1];
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[m - 1][n - 1];
}

void Solution_63::test(void)
{
    vector<vector<int>> obstacleGrid =
    {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 },
    };
    
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}
