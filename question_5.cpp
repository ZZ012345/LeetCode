//
//  question_5.cpp
//  LeetCode
//
//  Created by 周至 on 2024/4/9.
//

#include "header.h"

string Solution_5::longestPalindrome(string s)
{
    int n = (int)s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int max_len = 1, max_origin = 0;
    int miss_cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    
    for (int gap = 1; gap < n; gap++)
    {
        bool found = false;
        for (int i = 0; i + gap < n; i++)
        {
            if ((s[i] == s[i + gap]) && ((gap == 1) || dp[i + 1][i + gap - 1]))
            {
                found = true;
                dp[i][i + gap] = 1;
                if (gap + 1 > max_len)
                {
                    max_len = gap + 1;
                    max_origin = i;
                }
            }
        }
        
        /* 如果连续两个长度未找到，后续不可能再找到，终止循环 */
        miss_cnt = found ? 0 : (miss_cnt + 1);
        if (miss_cnt >= 2)
        {
            break;
        }
    }
    
    return s.substr(max_origin, max_len);
}

void Solution_5::test(void)
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
}
