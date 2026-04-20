//
//  question_20.cpp
//  LeetCode
//
//  Created by 周至 on 2024/3/20.
//

#include "header.h"

bool Solution_20::isValid(string s)
{
    stack<char> sta;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (('(' == s[i]) || ('{' == s[i]) || ('[' == s[i]))
        {
            sta.push(s[i]);
        }
        else
        {
            if (sta.empty())
            {
                return false;
            }
            
            if (((')' == s[i]) && ('(' != sta.top())) ||
                (('}' == s[i]) && ('{' != sta.top())) ||
                ((']' == s[i]) && ('[' != sta.top())))
            {
                return false;
            }
            
            sta.pop();
        }
    }
    
    return (0 == sta.size());
}

void Solution_20::test(void)
{
    string s = "(]";
    cout << isValid(s) << endl;
}
