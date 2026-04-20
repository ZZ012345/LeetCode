//
//  question_120.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/8.
//

#include "header.h"

int Solution_120::minimumTotal(vector<vector<int>> &triangle)
{
    int n = (int)triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int up_left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
            int up = (j < i) ? dp[i - 1][j] : INT_MAX;
            dp[i][j] = min(up_left, up) + triangle[i][j];
        }
    }
    
    int min_total = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        min_total = min(min_total, dp[n - 1][i]);
    }
    
    return min_total;
}

void Solution_120::test(void)
{
    vector<vector<int>> triangle =
    {
        { 2 },
        { 3, 4 },
        { 6, 5, 7 },
        { 4, 1, 8, 3 },
    };
    
    cout << minimumTotal(triangle) << endl;
}
