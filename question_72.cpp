//
//  question_72.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/9.
//

#include "header.h"

int Solution_72::minDistance(string word1, string word2)
{
    int m = (int)word1.length(), n = (int)word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] - 1) + 1;
            }
            else
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    
    return dp[m][n];
}

void Solution_72::test(void)
{
    string word1 = "intention";
    string word2 = "execution";
    
    cout << minDistance(word1, word2) << endl;
}
