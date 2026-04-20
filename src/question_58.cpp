//
//  question_58.cpp
//  LeetCode
//
//  Created by 周至 on 2025/7/15.
//

#include "header.h"

int Solution_58::lengthOfLastWord(string s)
{
    int len = 0, last_len = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            last_len = (len == 0) ? last_len : len;
            len = 0;
        }
        else if (i == s.length() - 1)
        {
            last_len = len + 1;
        }
        else
        {
            len++;
        }
    }
    
    return last_len;
}

void Solution_58::test(void)
{
    string s = "   fly me   to   the moon ";
    cout << lengthOfLastWord(s) << endl;
}
