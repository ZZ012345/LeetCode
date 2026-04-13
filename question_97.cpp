//
//  question_97.cpp
//  LeetCode
//
//  Created by 周至 on 2025/9/8.
//

#include "header.h"

bool Solution_97::isInterleave(string s1, string s2, string s3)
{
    int len1 = (int)s1.size(), len2 = (int)s2.size(), len3 = (int)s3.size();
    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, 0));
    
    if (len1 + len2 != len3)
    {
        return false;
    }
    
    dp[0][0] = true;
    for (int i = 1; i <= len3; i++)
    {
        /* s1:0~j-1,长度j; s2:0~i-j-1,长度i-j */
        for (int j = 0; j <= min(i, len1); j++)
        {
            if (i - j > len2)
            {
                continue;
            }
            
            if (j == 0)
            {
                dp[j][i - j] = dp[j][i - j - 1] && (s2[i - j - 1] == s3[i - 1]);
            }
            else if (i - j == 0)
            {
                dp[j][i - j] = (dp[j - 1][i - j] && (s1[j - 1] == s3[i - 1]));
            }
            else
            {
                dp[j][i - j] = (dp[j - 1][i - j] && (s1[j - 1] == s3[i - 1])) ||
                    (dp[j][i - j - 1] && (s2[i - j - 1] == s3[i - 1]));
            }
        }
    }
    
    return dp[len1][len2];
}

void Solution_97::test(void)
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    
    cout << isInterleave(s1, s2, s3) << endl;
}
