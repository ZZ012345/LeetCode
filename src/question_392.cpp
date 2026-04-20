//
//  question_392.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/18.
//

#include "header.h"

bool Solution_392::isSubsequence(string s, string t)
{
    vector<vector<int>> vec(26);
    int last_idx = -1;
    
    for (int i = 0; i < t.size(); i++)
    {
        vec[t[i] - 'a'].emplace_back(i);
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        bool find = false;
        for (const auto j : vec[s[i] - 'a'])
        {
            if (j > last_idx)
            {
                last_idx = j;
                find = true;
                break;
            }
        }
        if (!find)
        {
            return false;
        }
    }
    
    return true;
}

void Solution_392::test(void)
{
    string s = "axc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t) << endl;
}
