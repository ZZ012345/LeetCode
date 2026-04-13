//
//  question_14.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/15.
//

#include "header.h"

string Solution_14::longestCommonPrefix(vector<string> &strs)
{
    string prefix;
    
    for (int i = 0; i < strs[0].size(); i++)
    {
        char ch = strs[0][i];
        bool flag = true;
        for (int j = 1; j < strs.size(); j++)
        {
            if (i >= strs[j].size() || ch != strs[j][i])
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            prefix += ch;
        }
        else
        {
            break;
        }
    }
    
    return prefix;
}

void Solution_14::test(void)
{
    vector<string> strs = { "dog", "flow", "flight" };
    cout << longestCommonPrefix(strs) << endl;
}
